/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TimerIntLdd1.c
**     Project     : TFC2014-2
**     Processor   : MKL25Z128VLK4
**     Component   : TimerInt_LDD
**     Version     : Component 01.018, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-10-07, 18:49, # CodeGen: 15
**     Abstract    :
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : TimerIntLdd1
**          Periodic interrupt source                      : LPTMR0_CMR
**          Counter                                        : LPTMR0_CNR
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_LPTimer
**            Interrupt priority                           : maximal priority
**          Interrupt period                               : 30.517578 �s
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TU3
**     Contents    :
**         Init         - LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr);
**         Enable       - LDD_TError TimerIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable      - LDD_TError TimerIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask - LDD_TError TimerIntLdd1_SetEventMask(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file TimerIntLdd1.c
** @version 01.02
** @brief
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup TimerIntLdd1_module TimerIntLdd1 module documentation
**  @{
*/         

/* MODULE TimerIntLdd1. */

#include "cameraCLK.h"
#include "TimerIntLdd1.h"
/* {Default RTOS Adapter} No RTOS includes */

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TDeviceData *LinkedDeviceDataPtr;
  bool EnUser;                         /* Enable/Disable device */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} TimerIntLdd1_TDeviceData;

typedef TimerIntLdd1_TDeviceData *TimerIntLdd1_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static TimerIntLdd1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERINT_ON_INTERRUPT)
/* Internal method prototypes */
/*
** ===================================================================
**     Method      :  TimerIntLdd1_Init (component TimerInt_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TimerIntLdd1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  TimerIntLdd1_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  DeviceDataPrv->EnUser = TRUE;        /* Set the flag "device enabled" */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_TimerIntLdd1_ID,DeviceDataPrv);
  DeviceDataPrv->LinkedDeviceDataPtr = TU3_Init((LDD_TUserData *)NULL);
  if (DeviceDataPrv->LinkedDeviceDataPtr == NULL) { /* Is initialization of TimerUnit unsuccessful? */
    /* Unregistration of the device structure */
    PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_TimerIntLdd1_ID);
    /* Deallocation of the device structure */
    /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
    return NULL;                       /* If so, then the TimerInt initialization is also unsuccessful */
  }
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  TimerIntLdd1_Enable (component TimerInt_LDD)
*/
/*!
**     @brief
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask).
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TimerIntLdd1_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  TimerIntLdd1_TDeviceData *DeviceDataPrv = (TimerIntLdd1_TDeviceData *)DeviceDataPtr;

  if (!DeviceDataPrv->EnUser) {        /* Is the device disabled by user? */
    DeviceDataPrv->EnUser = TRUE;      /* If yes then set the flag "device enabled" */
    (void)TU3_Enable(DeviceDataPrv->LinkedDeviceDataPtr); /* Enable TimerUnit */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TimerIntLdd1_Disable (component TimerInt_LDD)
*/
/*!
**     @brief
**         Disables the component - it stops signal generation and
**         events calling.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TimerIntLdd1_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  TimerIntLdd1_TDeviceData *DeviceDataPrv = (TimerIntLdd1_TDeviceData *)DeviceDataPtr;

  if (DeviceDataPrv->EnUser) {         /* Is the device enabled by user? */
    DeviceDataPrv->EnUser = FALSE;     /* If yes then set the flag "device enabled" */
   (void)TU3_Disable(DeviceDataPrv->LinkedDeviceDataPtr); /* Disable TimerUnit component */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TimerIntLdd1_SetEventMask (component TimerInt_LDD)
*/
/*!
**     @brief
**         Enables/disables event(s). The events contained within the
**         mask are enabled. Events not contained within the mask are
**         disabled. The component event masks are defined in the
**         PE_Types.h file. Note: Event that are not generated (See the
**         "Events" tab in the Component inspector) are not handled by
**         this method. In this case the method returns ERR_PARAM_MASK
**         error code. See also method [GetEventMask].
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         EventMask       - Event mask
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_PARAM_MASK - Event mask is not valid
*/
/* ===================================================================*/
LDD_TError TimerIntLdd1_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask)
{
  TimerIntLdd1_TDeviceData *DeviceDataPrv = (TimerIntLdd1_TDeviceData *)DeviceDataPtr;

  /* Event mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((EventMask & ((LDD_TEventMask)~AVAILABLE_EVENTS_MASK)) != 0U) {
    return ERR_PARAM_MASK;
  }
  return TU3_SetEventMask(DeviceDataPrv->LinkedDeviceDataPtr, ((EventMask & LDD_TIMERINT_ON_INTERRUPT) != 0U) ? LDD_TIMERUNIT_ON_COUNTER_RESTART : (LDD_TEventMask)0U);
}

/*
** ===================================================================
**     Method      :  TU3_OnCounterRestart (component TimerInt_LDD)
**
**     Description :
**         The method services the event of the linked component TU3 and 
**         eventually invokes event TimerIntLdd1_OnInterrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU3_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
  TimerIntLdd1_TDeviceData *DeviceDataPrv = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TimerIntLdd1_ID];

  (void)UserDataPtr;                   /* Parameter is not used, suppress unused argument warning */
  TimerIntLdd1_OnInterrupt(DeviceDataPrv->UserDataPtr); /* Invoke OnInterrupt event */
}

/* END TimerIntLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
