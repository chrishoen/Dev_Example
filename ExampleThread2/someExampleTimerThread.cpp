/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExampleParms.h"
#include "someExampleQCallThread.h"

#define  _SOMEEXAMPLETIMERTHREAD_CPP_
#include "someExampleTimerThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExampleTimerThread::ExampleTimerThread()
{
   // Set base class variables.
   BaseClass::setThreadName("ExampleTimer");
   BaseClass::setThreadPrintLevel(gExampleParms.mPrintLevel);
   BaseClass::setThreadPriority(Cmn::gPriorities.mTimer);
   BaseClass::mTimerPeriod = gExampleParms.mTimerPeriod;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer. It
// invokes the example qcall thread qcall.

void ExampleTimerThread::executeOnTimer(int aTimeCount)
{
   Prn::print(Prn::View11, "ExampleTimerThread::executeOnTimer %d", aTimeCount);

   // Invoke the example qcall thread qcall.
   gExampleQCallThread->mExampleple1QCall(aTimeCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

}//namespace