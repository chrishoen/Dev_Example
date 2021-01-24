/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExamParms.h"
#include "someExamQCallThread.h"

#define  _SOMEXAMTIMERTHREAD_CPP_
#include "someExamTimerThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExamTimerThread::ExamTimerThread()
{
   // Set base class variables.
   BaseClass::setThreadName("ExamTimer");
   BaseClass::setThreadPrintLevel(gExamParms.mPrintLevel);
   BaseClass::setThreadPriority(Cmn::gPriorities.mTimer);
   BaseClass::mTimerPeriod = gExamParms.mTimerPeriod;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer. It
// invokes the example qcall thread qcall.

void ExamTimerThread::executeOnTimer(int aTimeCount)
{
   Prn::print(Prn::View11, "ExamTimerThread::executeOnTimer %d", aTimeCount);

   // Invoke the example qcall thread qcall.
   gExamQCallThread->mExample1QCall(aTimeCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

}//namespace