
typedef struct{
	int var; 
	int inst;
	int max; 
	float min;
	float moy;
	float sum;
	float sqrsum;
	
}val;

typedef struct{
    val vs ;
    uint16_t nbSamples ;
}valCalcStruct_16;

typedef struct{
	valCalcStruct_16 current;
	valCalcStruct_16 voltage; 
	valCalcStruct_16 phase;
	valCalcStruct_16 v_thd;
	valCalcStruct_16 c_thd;
	valCalcStruct_16 freq;
	valCalcStruct_16 powRmsApp;
	int AEnergie;
	int REnergie;
	int APEnergie;
	int FEnergie;
	int state;
	int waCtrlTimeout;
	int signalStuckScale;
}wAppStruct;




	
 