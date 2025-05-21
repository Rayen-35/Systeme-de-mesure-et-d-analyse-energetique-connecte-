/**
  ******************************************************************************
  * @file    metroTask.h
  * @author  AMG/IPC Application Team
  * @brief   This file contains all the functions prototypes for the metroTask
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

#ifndef METROTASK_H
#define METROTASK_H

/*******************************************************************************
* INCLUDE FILES:
*******************************************************************************/
#include "stpm_metrology.h"
#include "metrology.h"

/** @addtogroup LEGAL
  * @{
  */

/*******************************************************************************
* CONSTANTS & MACROS:
*******************************************************************************/

#define METRO_PHASE_1           0
#define METRO_PHASE_2           1
#define METRO_PHASE_3           2
#define METRO_MAX_PHASES        3

#define METRO_DATA_ACTIVE       0
#define METRO_DATA_REACTIVE     1
#define METRO_DATA_APPARENT     2

/*******************************************************************************
* TYPES:
*******************************************************************************/
typedef struct {
  uint32_t       config;
  uint32_t       data1[19];
  uint32_t       powerFact[2];
  uint32_t       voltageFact[2];
  uint32_t       currentFact[2];
} nvmLeg_t;

typedef struct
{
  uint8_t       metroTimerActive;
  uint8_t       nbPhase;
  int32_t       powerActive;
  int32_t       powerReactive;
  int32_t       powerApparent;
  int32_t       energyActive;
  int32_t       energyReactive;
  int32_t       energyApparent;
  uint32_t      rmsvoltage;
  uint32_t      rmscurrent;
} metroData_t;

  


/**
  ******************************************************************************

  * Description        : structures and variables for my metro app
                           
  ******************************************************************************
  */

typedef struct{
    int16_t var; 
    int16_t inst;
    int16_t max; 
    int16_t min;
    int16_t moy;
    int32_t sum;
    int32_t sqrsum;
}val;

typedef struct{
    val vs ;
    uint16_t nbSamples ;
}valCalcStruct_16;

typedef struct{
    val vs ;
    uint16_t nbSamples ;
}valSignedCalcStruct_16;


typedef struct{
  int64_t total;
  uint64_t lastVal;
  uint8_t initilized,overflowFlag;
}accumStruct;


typedef struct{
    valCalcStruct_16 current;
    valCalcStruct_16 voltage; 
    valCalcStruct_16 phase;
    valCalcStruct_16 v_thd;
    valCalcStruct_16 c_thd;
    valCalcStruct_16 freq;
    valSignedCalcStruct_16 powRmsApp;
    int64_t activw;
    int64_t reactw;
    int64_t fundw;
    int64_t appw;
    int32_t instVoltage;
    int32_t instCurrent;
    int powerSign;
    accumStruct AEnergie;
    accumStruct REnergie;
    accumStruct APEnergie;
    accumStruct FEnergie;
    int state;
    int waCtrlTimeout;
    int signalStuckScale;
}wAppStruct;







/*******************************************************************************
* GLOBAL VARIABLES:
*******************************************************************************/
extern metroData_t metroData[2][2];

/*******************************************************************************
* FUNCTIONS:
*******************************************************************************/
void METRO_Init();
void METRO_Update_Measures();
void METRO_Latch_Measures();
void METRO_Get_Measures();


/**
  ******************************************************************************  
  * Description        : fct prototypes for metro app
                   
  ******************************************************************************
  */

void VSC_init(valCalcStruct_16 * vsc);
void VSCS_init(valSignedCalcStruct_16 * vsc);
void VSC_reInit(valCalcStruct_16 * vsc);
void VSCS_reInit(valSignedCalcStruct_16 * vsc);
void VSC_routine(valCalcStruct_16 * vsc, uint32_t instVal);
void VSCS_routine(valSignedCalcStruct_16 * vsc, int16_t instVal);


void ACC_init(accumStruct * as,uint8_t overflowFlag);
void ACC_reInit(accumStruct * as);
void ACC_routine(accumStruct * as, int32_t instVal,uint8_t powerSign,uint8_t overflowed);

void WA_init(wAppStruct * wa);
void WA_reInit(wAppStruct * wa);
void WA_routine(wAppStruct * wa);

//************************************************
float CFac_current(void);



/**
  * @}
  */

#endif /* METROTASK_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
