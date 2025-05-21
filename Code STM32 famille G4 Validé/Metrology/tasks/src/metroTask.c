/**
  ******************************************************************************
  * @file    metroTask.c
  * @author  AMG/IPC Application Team
  * @brief   This source code includes Metrology legal task related functions
  * @brief
  @verbatim
  @endverbatim

  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/*******************************************************************************
* INCLUDE FILES:
*******************************************************************************/
#include "metroTask.h"
#include "metrology.h"
#include <stdint.h>
#include "stdio.h"
#include "st_device.h"
#include "metrology_hal.h"
#include "stdlib.h"

/** @addtogroup LEGAL
  * @{
  */

/*******************************************************************************
* CONSTANTS & MACROS:
*******************************************************************************/

#define FACTOR_POWER_ON_ENERGY      (858)   // (3600 * 16000000 / 0x4000000) = 858.3...
#define MAX_STUCK_SCALE 3

       /*+------------------------------------------------------------------------------------+
         |                                        U32                                         |
         |---------------------|-------------------|-------------------|----------------------|
         |     STPM EXT4       |     STPM EXT3     |     STPM EXT2     |     STPM EXT1        |
         |---------------------|-------------------|-------------------|----------------------|
         |    u4   |     u4    |   u4    |   u4    |     u4  |     u4  |      u4   |  u4      |
         |---------|-----------|--------------------------------------------------------------|
         |CH masks | STPM type |CH masks |STPM type|CH masks |STPM type|  CH masks |STPM type |
         |---------|-----------|--------------------------------------------------------------|

        STPM CFG EXTx (u8):
        -----------------
        MSB u4 : Channel  Mask :  Channels affected to STPM
            0 : No Channel affected
            1 : Channel 1 affected
            2 : Channel 2 affected
            4 : Channel 3 affected
            8 : Channel 4 affected

        LSB u4 :  STPM type : 6 to 8
            0 : No STPM
            6 : STPM32
            7 : STPM33
            8 : STPM34

        EX : STPM EXT 1: One STPM34 with Channels 2 and 3 affected on it
        LSB u4 = 8 (STPM34)
        MSB u4 = 6 ( 4:Channel 3 + 2:Channel 2)

        STPM CONFIG : U32 = 0x00000068

        +------------------------------------------------------------------------------------+*/
#define DPOW        (268435456.0)   // put 2^28 for 28 bits
//#define CALIB_V      (0.875)  //default Calibration value (Middle value)
#define CALIB_I      (0.875) //default Calibration value (Midle Value)
#define KINT        (1.0)         // this value is used only for rogowski,  otherwise = 1
//#define R1          (780000.0)  // External resistor for ADC
//#define R2          (470.0)    // External Resistor for ADC
//#define AU          (2.0)   //( ADC Voltage Gain )
#define AI          (2.0)   // (ADC Current Gain )
#define VREF        (1.18)  //( ADC vref)
#define KSI         (0.00061111)    // Value for a shunt KSI = RShunt in ohms
//#define F_XTAL      (16000000.0)  // frenquency of the Main Clock


const nvmLeg_t metroDefault = {
  {                 // config
    0x00006868
  },
  {                 // data1[19] STPM (Config for CT)
    0x040000a0,
    0x240000a0,
    0x0000c4e0,
    0x00000000,
    0x003ff800,
    0x003ff800,
    0x003ff800,
    0x003ff800,
    0x00000fff,
    0x00000fff,
    0x00000fff,
    0x00000fff,
    0x03270327,
    0x03270327,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00004007,
 },
  {                // powerFact[2]
    30154605,      // ch 1
    30154605      // ch 2
  },
  {                // voltageFact[2]
    116274,        // ch 1
    116274        // ch 2
  },
  {                // currentFact[2]
    25934,         // ch 1
    25934         // ch 2
  }
};

#ifdef UART_XFER_STPM3X /* UART MODE */   

const STPM_Com_port_t STPM_com_port[1] ={  
  {
  USART3,    //USART used by device 1
  CS_GPIO_type,     //CS used by device 1
  CS_GPIO_pin,
  SYN_GPIO_type,     //SYN used by device 1
  SYN_GPIO_pin,
  EN_GPIO_type,     //EN used by device 1
  EN_GPIO_pin
  }
};
#endif

#ifdef SPI_XFER_STPM3X /* SPI MODE */   

const STPM_Com_port_t STPM_com_port[2] ={  
  {
  SPI2,    //SPI used by device 1
  GPIOB,     //CS used by device 1
  GPIO_PIN_12,
  GPIOA,     //SYN used by device 1
  GPIO_PIN_10,
  GPIOC,     //EN used by device 1
  GPIO_PIN_5
  },
  {
  SPI2,    //SPI used by device 
  GPIOA,     //CS used by device 2
  GPIO_PIN_15,
  GPIOA,     //SYN used by device 
  GPIO_PIN_10,
  GPIOC,     //EN used by device 2
  GPIO_PIN_1
  }
};

#endif

/*******************************************************************************
* TYPES:
*******************************************************************************/

/*******************************************************************************
* GLOBAL VARIABLES:
*******************************************************************************/
metroData_t metroData[2][2];
METRO_Device_Config_t Tab_METRO_Global_Devices_Config[NB_MAX_DEVICE];

extern METRO_Device_Config_t Tab_METRO_internal_Devices_Config[NB_MAX_DEVICE];

/*******************************************************************************
* LOCAL FUNCTION PROTOTYPES:
*******************************************************************************/
static void METRO_UpdateData(void);
static void Metro_com_port_device(void);

/*******************************************************************************
* LOCAL VARIABLES:
*******************************************************************************/

/*******************************************************************************
*
*                       IMPLEMENTATION: Public functions
*
*******************************************************************************/


/*******************************************************************************
*
*                       IMPLEMENTATION: Private functions
*
*******************************************************************************/

/**
  * @brief  This function implements the Metrology init
  * @param  None
  * @retval None
  */
void METRO_Init()
{
  /* initialization device type and number of channel */
  Metro_Setup((uint32_t)metroDefault.config); 
  
  /* initialization device communication port */ 
  Metro_com_port_device();

  /*power STPM properly with EN pin to set it in UART or SPI mode*/
  Metro_power_up_device();
  
  /* initialization steps for STPM device */
    
  
  //Metro_HAL_Stpm_write(EXT2,0x00,1,&Tab_METRO_internal_Devices_Config[EXT2].metro_stpm_reg.DSPCTRL1,STPM_WAIT);
  //Metro_HAL_Stpm_Read(EXT2, 0x00, 1, (uint32_t*)&Tab_METRO_internal_Devices_Config[EXT2].metro_stpm_reg.DSPCTRL1);
  
  
  Metro_Init();
  
#ifdef UART_XFER_STPM3X /* UART MODE */   
  /* Change UART speed for STPM communication between Host and EXT1*/
  Metro_UartSpeed(USART_SPEED); 
#endif
  
  /* Write configuration to STPM device and read back configuration from STPM device */   
  Metro_ApplyConfig((uint32_t)metroDefault.config,(uint32_t)metroDefault.data1);
  
  

/* Initialize the factors for the computation */
  for(int i=0;i<NB_MAX_CHANNEL;i++)
  {
  Metro_Set_Hardware_Factors( (METRO_Channel_t)(CHANNEL_1+i), (uint32_t)metroDefault.powerFact[i], (uint32_t)metroDefault.powerFact[i]/ FACTOR_POWER_ON_ENERGY,(uint32_t)metroDefault.voltageFact[i],(uint32_t)CFac_current());
  }
   
  for (int i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
      /* Set default latch device type inside Metro struct for Ext chips */
      Metro_Register_Latch_device_Config_type((METRO_NB_Device_t)i, LATCH_SW);
    }
  }
}


/**
  * @brief  This function implements the Metrology update data
  *         Pickup the data 
  * @param  None
  * @retval None
  */
void METRO_Update_Measures()
{
  //if(Tab_METRO_internal_Devices_Config[EXT1].device != 0)
  //{
    METRO_UpdateData();
  //}
}

/**
  * @brief  This function implements the Metrology latch device
  *         Set the HW latch for next update
  * @param  None
  * @retval None
  */
void METRO_Latch_Measures()
{
  METRO_NB_Device_t i;

  for (i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
      Metro_Set_Latch_device_type(i,LATCH_SW);
    }
  }
  //Metro_Set_Latch_device_type(EXT2,LATCH_SW);
}

/**
  * @brief  This function implements the Metrology get DSP data inside device
  * @param  None
  * @retval None
  */
void METRO_Get_Measures()
{
//METRO_NB_Device_t i;

  //for (i=EXT1;i<(NB_MAX_DEVICE);i++)
  //{
    //if(Tab_METRO_internal_Devices_Config[i].device != 0)
    //{
      Metro_Get_Data_device(EXT1);
    //}
  //}
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
      
      Metro_Get_Data_device(EXT2);
      
}

/**
  * @brief  This function updates the Metro measurements values
  * @param  None
  * @retval None
  */
static void METRO_UpdateData(void)
{
  
  for (int i=0; i<2; i++)
  {
     for (int j=0; j<2; j++)
  { 
  metroData[i][j].energyActive   = Metro_Read_energy(i+1, j+1, E_W_ACTIVE);
  metroData[i][j].energyReactive = Metro_Read_energy(i+1, j+1, E_REACTIVE);
  metroData[i][j].energyApparent = Metro_Read_energy(i+1, j+1, E_APPARENT);
  
  metroData[i][j].powerActive = Metro_Read_Power(i+1, j+1, W_ACTIVE);
  metroData[i][j].powerReactive = Metro_Read_Power(i+1, j+1, REACTIVE);
  metroData[i][j].powerApparent = Metro_Read_Power(i+1, j+1, APPARENT_RMS);
    
  Metro_Read_RMS(i+1,j+1,&metroData[i][j].rmsvoltage,&metroData[i][j].rmscurrent,1);
  }
  }
}

/**
  * @brief  Initialize the Port to communicated to Metrology peripheral
  *         
  * @param[in]   None
  * @retval None
  */

static void Metro_com_port_device(void)
{

  for (METRO_NB_Device_t i=EXT1;i<(NB_MAX_DEVICE);i++)
  {
    if(Tab_METRO_internal_Devices_Config[i].device != 0)
    {
     Tab_METRO_internal_Devices_Config[i].STPM_com_port= STPM_com_port[(i-1)];
    }
  }

}



/**
  ******************************************************************************

  * Description        : fuctions added by me for metro app          
                 
  ******************************************************************************
  */
void VSC_init(valCalcStruct_16 * vsc){
  vsc->vs.var=0;
  vsc->vs.inst=0;
  vsc->vs.min=0;
  vsc->vs.max=0;
  vsc->vs.moy=0;
  vsc->vs.sum=0;
  vsc->vs.sqrsum=0;
  vsc->nbSamples=0;
}
void VSCS_init(valSignedCalcStruct_16 * vsc){
  vsc->vs.var=0;
  vsc->vs.inst=0;
  vsc->vs.min=0;
  vsc->vs.max=0;
  vsc->vs.moy=0;
  vsc->vs.sum=0;
  vsc->vs.sqrsum=0;
  vsc->nbSamples=0;
}

void VSC_reInit(valCalcStruct_16 * vsc){
  vsc->vs.var=0;
  vsc->vs.min=vsc->vs.inst;
  vsc->vs.max=vsc->vs.inst;
  vsc->vs.moy=vsc->vs.inst;
  vsc->vs.sum=vsc->vs.inst;
  vsc->vs.sqrsum=0;
  vsc->nbSamples=1;
}
void VSCS_reInit(valSignedCalcStruct_16 * vsc){
  vsc->vs.var=0;
  vsc->vs.min=vsc->vs.inst;
  vsc->vs.max=vsc->vs.inst;
  vsc->vs.moy=vsc->vs.inst;
  vsc->vs.sum=vsc->vs.inst;
  vsc->vs.sqrsum=0;
  vsc->nbSamples=1;
}
void VSC_routine(valCalcStruct_16 * vsc, uint32_t instVal){
  if(vsc->vs.max<instVal){
    vsc->vs.max=instVal;
  }
  if(vsc->vs.min>instVal||vsc->nbSamples==0){
    vsc->vs.min=instVal;
  }
  vsc->vs.sum+=instVal;
  //vsc->vs.sqrsum+=instVal*instVal;
  int16_t delta=instVal-vsc->vs.moy;
  vsc->vs.moy=vsc->vs.sum/(vsc->nbSamples+1);
  if(vsc->nbSamples){
    int16_t delta2 = instVal - vsc->vs.moy;
    vsc->vs.sqrsum += delta*delta2;
  }
  vsc->vs.var=vsc->vs.sqrsum/(vsc->nbSamples);
  vsc->nbSamples++;
  vsc->vs.inst=instVal;
}
void VSCS_routine(valSignedCalcStruct_16 * vsc, int16_t instVal){
  if(vsc->vs.max<abs(instVal)){
    vsc->vs.max=instVal;
  }
  if(vsc->vs.min>abs(instVal)||vsc->nbSamples==0){
    vsc->vs.min=instVal;
  }
  vsc->vs.sum+=instVal;
  //vsc->vs.sqrsum+=instVal*instVal;
  int16_t delta=instVal-vsc->vs.moy;
  vsc->vs.moy=vsc->vs.sum/(vsc->nbSamples+1);
  if(vsc->nbSamples){
    int16_t delta2 = instVal - vsc->vs.moy;
    vsc->vs.sqrsum += delta*delta2;
  }
  vsc->vs.var=vsc->vs.sqrsum/(vsc->nbSamples);
  vsc->nbSamples++;
  vsc->vs.inst=instVal;
}

//****************************ACC functions**************************

void ACC_init(accumStruct * as,uint8_t overflowFlag){
  as->initilized=0;
  as->total=0;
  as->overflowFlag=overflowFlag;
}
void ACC_reInit(accumStruct * as){
  as->initilized=2;
}
int32_t overflow_count;

void ACC_routine(accumStruct * as, int32_t instVal,uint8_t powerSign,uint8_t overflowed){
  //uint8_t calcOverflow=0;
  if(as->initilized==0){
    as->total=0;
    as->initilized=1;
  }else if(as->initilized==2){
    as->initilized=1;
  }else{
    as->total+=(int32_t)(instVal-(int32_t)as->lastVal);
  }
  as->lastVal=(uint32_t)instVal;
  
  /*
  if(powerSign){
    if(as->lastVal>(uint32_t)instVal){
      if(as->lastVal>0xB0000000&&((uint32_t)instVal)<0x40000000)
        calcOverflow=1;
    }
  }else{
    if(as->lastVal<(uint32_t)instVal){
      if(instVal>0xB0000000&&((uint32_t)as->lastVal)<0x40000000)
        calcOverflow=1;
    }
  }
*/
  as->lastVal=(uint32_t)instVal;
  if(as->initilized==0){
    if(powerSign)
      overflow_count=0;
    else
      overflow_count=0xFFFFFFFF;
    as->initilized=1;
  }else
    overflow_count=as->total>>32;
  if(overflowed){
    if(powerSign)
      overflow_count++;
    else
      overflow_count--;
  }
  //as->total=(((uint64_t)overflow_count)<<32)|(uint32_t)instVal;
  //ACC_checkOverflow(as,ws,as->overflowFlag);
}



//**************************************enrgy app fcts*******************************


void WA_init(wAppStruct * wa){
  VSC_init(&wa->current);
  VSC_init(&wa->phase);
  VSC_init(&wa->voltage);
  VSC_init(&wa->v_thd);
  VSC_init(&wa->c_thd);
  VSC_init(&wa->freq);
  VSCS_init(&wa->powRmsApp);
  wa->activw=0;
  wa->reactw=0;
  wa->fundw=0;
  wa->appw=0;
  ACC_init(&wa->AEnergie,0);
  ACC_init(&wa->REnergie,0);
  ACC_init(&wa->APEnergie,0);
  ACC_init(&wa->FEnergie,0);
  
  //wa->state=WA_GRACE;
  //wa->waCtrlTimeout=WA_CTR_GRACE_TIEMOUT;
  
  wa->signalStuckScale=0;
}


void WA_reInit(wAppStruct * wa){
  VSC_reInit(&wa->current);
  VSC_reInit(&wa->phase);
  VSC_reInit(&wa->voltage);
  VSC_reInit(&wa->v_thd);
  VSC_reInit(&wa->c_thd);
  VSCS_reInit(&wa->powRmsApp);
  ACC_reInit(&wa->AEnergie);
  ACC_reInit(&wa->REnergie);
  ACC_reInit(&wa->FEnergie);
  ACC_reInit(&wa->APEnergie);
}


void WA_routine(wAppStruct * wa){
  //if(!WA_superControllerRoutine(wa,regmap,idCh))
    //return ;
  VSC_routine(&wa->current,Metro_HAL_read_RMS_Current(EXT1,INT_CHANNEL_1));
  //printf("%d",wa->current.vs.min);
  //printf("-");
  VSC_routine(&wa->phase,Metro_HAL_read_PHI(EXT1,INT_CHANNEL_1));
  //printf("%d",wa->phase.vs.moy);
  //printf("-");
  VSC_routine(&wa->voltage,Metro_HAL_read_RMS_Voltage(EXT1,CHANNEL_1));
  //printf("%d",wa->voltage.vs.min);
  //printf("-");
  VSC_routine(&wa->freq,Metro_Read_Period(INT_CHANNEL_1));
  //printf("%d",wa->freq.vs.moy);
  //printf("-");
  VSCS_routine(&wa->powRmsApp,Metro_HAL_read_power(EXT1,CHANNEL_1,APPARENT_RMS));
  if(wa->instVoltage==Metro_HAL_read_Momentary_Voltage(EXT1,CHANNEL_1,V_FUND)&& wa->instCurrent==Metro_HAL_read_Momentary_Current(EXT1,CHANNEL_1,C_FUND))
    if(wa->signalStuckScale<MAX_STUCK_SCALE)
      wa->signalStuckScale++;
  else
    wa->signalStuckScale=0;
  wa->instVoltage=Metro_HAL_read_Momentary_Voltage(EXT1,CHANNEL_1,V_FUND);
  wa->instCurrent=Metro_HAL_read_Momentary_Current(EXT1,CHANNEL_1,C_FUND);
  wa->activw=Metro_HAL_read_energy(EXT1,CHANNEL_1,E_W_ACTIVE);
  wa->reactw=Metro_HAL_read_energy(EXT1,CHANNEL_1,E_REACTIVE);
  wa->fundw=Metro_HAL_read_energy(EXT1,CHANNEL_1,E_F_ACTIVE);
  wa->appw=Metro_HAL_read_energy(EXT1,CHANNEL_1,E_APPARENT);
  wa->powerSign=Metro_HAL_Read_Live_Event_from_Channel(EXT1,CHANNEL_1,LIVE_EVENT_CURRENT_SIGN_CHANGE_ACTIVE_POWER);  //cond on active power sign 
  /*if(idCh==0){
    ACC_routine(&wa->AEnergie,wa->activw,!SF_getDspEv1Masked(regmap,STPM_SIGN_ACTE),SF_getDspSr1Masked(regmap,STPM_P1_OVERFLOW_ACTE),MACHINE_getWscale());
    ACC_routine(&wa->REnergie,wa->reactw,!SF_getDspEv1Masked(regmap,STPM_SIGN_REACTE),SF_getDspSr1Masked(regmap,STPM_P1_OVERFLOW_REACTE),MACHINE_getWscale());
    ACC_routine(&wa->FEnergie,wa->fundw,!SF_getDspEv1Masked(regmap,STPM_SIGN_FUNDE),SF_getDspSr1Masked(regmap,STPM_P1_OVERFLOW_FUNDE),MACHINE_getWscale());
    ACC_routine(&wa->APEnergie,wa->appw,!SF_getDspEv1Masked(regmap,STPM_SIGN_APPE),SF_getDspSr1Masked(regmap,STPM_P1_OVERFLOW_APPE),MACHINE_getWscale());
  }else{*/
    ACC_routine(&wa->AEnergie,wa->activw,!Metro_HAL_Read_Live_Event_from_Channel(EXT1,CHANNEL_1,LIVE_EVENT_CURRENT_SIGN_CHANGE_ACTIVE_POWER),Metro_HAL_Read_Status_from_Channel(EXT1,CHANNEL_1,STATUS_CURRENT_OVERFLOW_ACTIVE_NRJ));
    //printf("_accnrj_");
    //printf("%d",wa->activw);
    ACC_routine(&wa->REnergie,wa->reactw,!Metro_HAL_Read_Live_Event_from_Channel(EXT1,CHANNEL_1,LIVE_EVENT_CURRENT_SIGN_CHANGE_REACTIVE_POWER),Metro_HAL_Read_Status_from_Channel(EXT1,CHANNEL_1,STATUS_CURRENT_OVERFLOW_REACTIVE_NRJ));
    //printf("%d",wa->REnergie.total);
    //printf("******\n");
    ACC_routine(&wa->FEnergie,wa->fundw,!Metro_HAL_Read_Live_Event_from_Channel(EXT1,CHANNEL_1,LIVE_EVENT_CURRENT_SIGN_CHANGE_FUNDAMENTAL_POWER),Metro_HAL_Read_Status_from_Channel(EXT1,CHANNEL_1,STATUS_CURRENT_OVERFLOW_FUNDAMENTAL_NRJ));
    ACC_routine(&wa->APEnergie,wa->appw,!Metro_HAL_Read_Live_Event_from_Channel(EXT1,CHANNEL_1,LIVE_EVENT_CURRENT_SIGN_CHANGE_APPARENT_POWER),Metro_HAL_Read_Status_from_Channel(EXT1,CHANNEL_1,STATUS_CURRENT_OVERFLOW_APPARENT_NRJ));
  }
//  int16_t v_thd_ieee=(int32_t)(idCh?regmap->v2:regmap->v1)*(int32_t)(idCh?regmap->v2:regmap->v1)-(int32_t)(idCh?regmap->v2Fund:regmap->v1Fund)*(int32_t)(idCh?regmap->v2Fund:regmap->v1Fund)/(idCh?regmap->v2Fund:regmap->v1Fund)*(int32_t)(idCh?regmap->v2Fund:regmap->v1Fund);
//  int16_t c_thd_ieee=(int32_t)(idCh?regmap->c2:regmap->c1)*(int32_t)(idCh?regmap->c2:regmap->c1)-(int32_t)(idCh?regmap->c2Fund:regmap->c1Fund)*(int32_t)(idCh?regmap->c2Fund:regmap->c1Fund)/(idCh?regmap->c2Fund:regmap->c1Fund)*(int32_t)(idCh?regmap->c2Fund:regmap->c1Fund);
//  VSC_routine(&wa->v_thd,v_thd_ieee);
//  VSC_routine(&wa->c_thd,c_thd_ieee);
//}


//*********************************factors calc**************************************************************

float CFac_current(void)
{
   return (VREF*100) / (AI * CALIB_I * KSI * KINT );
}  




/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
