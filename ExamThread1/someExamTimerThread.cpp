/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "risThreadsPriorities.h"

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
   BaseClass::setThreadPrintLevel(3);
   BaseClass::setThreadPriority(Ris::Threads::gPriorities.mTimerTest);
   BaseClass::mTimerPeriod = 1000;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class overload. This is executed periodically, in the context
// of the thread.

void ExamTimerThread::executeOnTimer(int aTimeCount)
{
   Prn::print(Prn::View11, "ExamTimerThread::executeOnTimer %d", aTimeCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

}//namespace