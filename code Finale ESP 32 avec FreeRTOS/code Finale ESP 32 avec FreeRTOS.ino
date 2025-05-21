#include <ArduinoJson.h>


#include <WiFi.h>
#include <PubSubClient.h>
#include <WebServer.h> 

#define UART_RX_PIN 3
#define UART_TX_PIN 1

#define daliRxPin 16
#define daliTxPin 17

#define WIFI_SSID "RaYEN"
#define WIFI_PASSWORD "12345678"

#define MQTT_SERVER "192.168.1.15"
#define MQTT_PORT 1883
#define MQTT_TOPIC "CURSEN_DATA"


struct SensorValues {
  int device;
  int16_t tension_moy, tension_inst, tension_max, tension_min, courant_moy, courant_inst, courant_max, courant_min, puissance_act, puissance_react, puissance_appar, V_THD, C_THD;
  int64_t energie_act, energie_react, energie_appar, accumulateur;
};

IPAddress ip(192, 168, 1, 123); 
IPAddress gateway(192, 168, 1, 1); 
IPAddress subnet(255, 255, 255, 0);


SensorValues sensorData;
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
char jsonfile[1500]; 

void taskSerial(void *pvParameters);
void taskJsonConversion(void *pvParameters);
void taskMQTT(void *pvParameters);
void taskHTTPServer(void *pvParameters); 


TaskHandle_t serialTaskHandle;
TaskHandle_t jsonTaskHandle;
TaskHandle_t mqttTaskHandle;
TaskHandle_t httpTaskHandle; 

WebServer server(80); 

void setup() {
  Serial.begin(115200); 
  pinMode(UART_RX_PIN, INPUT); 
  pinMode(UART_TX_PIN, OUTPUT);

 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to WiFi.");

  
  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);

 
  xTaskCreatePinnedToCore(
    taskSerial,
    "SerialTask",
    2048,  
    NULL,
    1, 
    &serialTaskHandle,
    0);  

  xTaskCreatePinnedToCore(
    taskJsonConversion,
    "JsonTask",
    2048,  
    NULL,
    1,  
    &jsonTaskHandle,
    0); 

    xTaskCreatePinnedToCore(
    taskMQTT,
    "MQTTTask",
    2048,
    NULL,
    1,
    &mqttTaskHandle,
    0);

     xTaskCreatePinnedToCore(
    taskHTTPServer,
    "HTTPServerTask",
    4096, 
    NULL,
    1,
    &httpTaskHandle,
    0);




  WiFi.config(ip, gateway, subnet);

}


void loop() {

}

void taskSerial(void *pvParameters) {
  (void) pvParameters;

  while (true) {
     if (Serial.available() > 0) {
      String receivedData = Serial.readStringUntil('\n');
      if (receivedData.length() > 0) {
        sscanf(receivedData.c_str(), "%d, %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd16 ", %" SCNd64 ",%" SCNd64 ",%" SCNd64 ", %" SCNd16 ",%" SCNd16 ",%" SCNd16 ",%" SCNd16 ", %" SCNd16 ", %" SCNd64"",
               &sensorData.device, &sensorData.tension_moy, &sensorData.tension_inst, &sensorData.tension_max, &sensorData.tension_min,
               &sensorData.courant_moy, &sensorData.courant_inst, &sensorData.courant_max, &sensorData.courant_min,
               &sensorData.energie_act, &sensorData.energie_react, &sensorData.energie_appar,
               &sensorData.puissance_act, &sensorData.puissance_react, &sensorData.puissance_appar,
               &sensorData.V_THD, &sensorData.C_THD, &sensorData.accumulateur);
        
       
        xTaskNotify(jsonTaskHandle, (uint32_t)&sensorData, eSetValueWithOverwrite);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);  
  }
}



void taskJsonConversion(void *pvParameters) {
  (void) pvParameters;

  while (true) {
    uint32_t notification;
    if (xTaskNotifyWait(0, ULONG_MAX, &notification, portMAX_DELAY) == pdPASS) {
    
      SensorValues *data = (SensorValues *)notification;

 
      DynamicJsonDocument doc(1500);
      doc["device"] = data->device;
      doc["tension_moy"] = data->tension_moy;
      doc["tension_inst"] = data->tension_inst;
      doc["tension_max"] = data->tension_max;
      doc["tension_min"] = data->tension_min;

      doc["courant_moy"] = data->courant_moy;
      doc["courant_inst"] = data->courant_inst;
      doc["courant_max"] = data->courant_max;
      doc["courant_min"] = data->courant_min;

      doc["energie_act"] = data->energie_act;
      doc["energie_react"] = data->energie_react;
      doc["energie_appar"] = data->energie_appar;

      doc["puissance_act"] = data->puissance_act;
      doc["puissance_react"] = data->puissance_react;
      doc["puissance_appar"] = data->puissance_appar;

      doc["V_THD"] = data->V_THD;
      doc["C_THD"] = data->C_THD;
      doc["accumulateur"] = data->accumulateur;

      serializeJson(doc, jsonfile, sizeof(jsonfile));

      Serial.println("jsonfile = ");
      Serial.println(jsonfile);

      xTaskNotify(mqttTaskHandle, (uint32_t)jsonfile, eSetValueWithOverwrite);
    }
  }
}

void taskMQTT(void *pvParameters) {
  (void) pvParameters;

  while (true) {
    uint32_t notification;
    if (xTaskNotifyWait(0, ULONG_MAX, &notification, portMAX_DELAY) == pdPASS) {
 
      char *jsonfile = (char *)notification;

      if (!mqttClient.connected()) {
        if (mqttClient.connect("ESP32Client")) {
          Serial.println("Connected to MQTT broker.");
        } else {
          Serial.println("Connection to MQTT broker failed.");
          vTaskDelay(5000 / portTICK_PERIOD_MS);
          continue;
        }
      }

      if (mqttClient.connected() && strlen(jsonfile) > 0) {
        mqttClient.publish(MQTT_TOPIC, jsonfile);
        Serial.println("Data sent to MQTT broker.");
        
      }
    }

    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}



void taskHTTPServer(void *pvParameters) {
  (void) pvParameters;

  server.on("/", HTTP_GET, [](){
    DynamicJsonDocument doc(512); 

  
    String jsonRequest = server.arg("plain");

  
    DeserializationError error = deserializeJson(doc, jsonRequest);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      server.send(400, "text/plain", "Erreur de désérialisation JSON."); // text/plain == le type de contenu
      return;
    }

 
    if (doc.containsKey("pourcentage")) {
     
      int pourcentage = doc["pourcentage"];

     
      Serial.print("Pourcentage reçu: ");
      Serial.println(pourcentage);
    
     
      int gradation = map(pourcentage, 0, 100, 0, 255); 

      
      Serial2.begin(115200, SERIAL_8N1, daliTxPin); 
      Serial2.write(gradation); 

  
    } else {
      server.send(400, "text/plain", "Clé 'pourcentage' manquante dans le JSON.");
    }
  });

  server.begin();

  while (true) {
    server.handleClient();
        if (Serial2.available() > 0) {
      
      String response = Serial2.readString();
       
      
         Serial.print("Réponse DALI 2.0 : ");
    
      server.send(200, "text/plain", response); 
    }
    vTaskDelay(10);
  }
}


