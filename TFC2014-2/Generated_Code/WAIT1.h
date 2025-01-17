/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : WAIT1.h
**     Project     : TFC2014-2
**     Processor   : MKL25Z128VLK4
**     Component   : Wait
**     Version     : Component 01.057, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-10-07, 11:09, # CodeGen: 0
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         Wait10Cycles  - void WAIT1_Wait10Cycles(void);
**         Wait100Cycles - void WAIT1_Wait100Cycles(void);
**         WaitCycles    - void WAIT1_WaitCycles(word cycles);
**         Waitms        - void WAIT1_Waitms(word ms);
**         Waitus        - void WAIT1_Waitus(word us);
**         Waitns        - void WAIT1_Waitns(word ns);
**         WaitOSms      - void WAIT1_WaitOSms(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     This an open source software implementing waiting routines using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file WAIT1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup WAIT1_module WAIT1 module documentation
**  @{
*/         

#ifndef __WAIT1_H
#define __WAIT1_H

/* MODULE WAIT1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"


#define WAIT1_NofCyclesMs(ms, hz)  ((ms)*((hz)/1000)) /* calculates the needed cycles based on bus clock frequency */
#define WAIT1_NofCyclesUs(us, hz)  ((us)*(((hz)/1000)/1000)) /* calculates the needed cycles based on bus clock frequency */
#define WAIT1_NofCyclesNs(ns, hz)  (((ns)*(((hz)/1000)/1000))/1000) /* calculates the needed cycles based on bus clock frequency */


#define WAIT1_WAIT_C(cycles) \
     ( (cycles)<=10 ? \
          WAIT1_Wait10Cycles() \
        : WAIT1_WaitCycles((word)cycles) \
      )                                      /*!< wait for some cycles */


void WAIT1_Wait10Cycles(void);
/*
** ===================================================================
**     Method      :  WAIT1_Wait10Cycles (component Wait)
**     Description :
**         Wait for approximately 10 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_Wait100Cycles(void);
/*
** ===================================================================
**     Method      :  WAIT1_Wait100Cycles (component Wait)
**     Description :
**         Wait for 100 CPU cycles.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_WaitCycles(word cycles);
/*
** ===================================================================
**     Method      :  WAIT1_WaitCycles (component Wait)
**     Description :
**         Wait for 100 CPU cycles.
**     Parameters  :
**         NAME            - DESCRIPTION
**         cycles          - The number of cycles to wait.
**     Returns     : Nothing
** ===================================================================
*/

void WAIT1_Waitms(word ms);
/*
** ===================================================================
**     Method      :  WAIT1_Waitms (component Wait)
**     Description :
**         Wait for a specified time in milliseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ms              - How many milliseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/

/* we are having a static clock configuration: implement as macro/inlined version */
#define WAIT1_Waitus(us)  \
       (  ((WAIT1_NofCyclesUs((us),CPU_BUS_CLK_HZ)==0)||(us)==0) ? \
          (void)0 : \
          ( ((us)/1000)==0 ? (void)0 : WAIT1_Waitms((word)((us)/1000))) \
          , (WAIT1_NofCyclesUs(((us)%1000), CPU_BUS_CLK_HZ)==0) ? (void)0 : \
            WAIT1_WAIT_C(WAIT1_NofCyclesUs(((us)%1000), CPU_BUS_CLK_HZ)) \
       )
/*
** ===================================================================
**     Method      :  WAIT1_Waitus (component Wait)
**     Description :
**         Wait for a specified time in microseconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         us              - How many microseconds the function has to
**                           wait
**     Returns     : Nothing
** ===================================================================
*/

/* we are having a static clock configuration: implement as macro/inlined version */
#define WAIT1_Waitns(ns)  \
       (  ((WAIT1_NofCyclesNs((ns), CPU_BUS_CLK_HZ)==0)||(ns)==0) ? \
          (void)0 : \
          WAIT1_Waitus((ns)/1000) \
          , (WAIT1_NofCyclesNs((ns)%1000, CPU_BUS_CLK_HZ)==0) ? \
              (void)0 : \
              WAIT1_WAIT_C(WAIT1_NofCyclesNs(((ns)%1000), CPU_BUS_CLK_HZ)) \
       )
/*
** ===================================================================
**     Method      :  WAIT1_Waitns (component Wait)
**     Description :
**         Wait for a specified time in nano seconds.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ns              - How many ns the function has to wait
**     Returns     : Nothing
** ===================================================================
*/

#define WAIT1_WaitOSms(ms) \
  WAIT1_Waitms(ms) /* no RTOS used, so use normal wait */
/*
** ===================================================================
**     Method      :  WAIT1_WaitOSms (component Wait)
**     Description :
**         If an RTOS is enabled, this routine will use a non-blocking
**         wait method. Otherwise it will do a busy/blocking wait.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END WAIT1. */

#endif
/* ifndef __WAIT1_H */
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
