/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "someExamParms.h"

#define  _SOMEEXAMQCALLTHREAD_CPP_
#include "someExamQCallThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExamQCallThread::ExamQCallThread()
{
   // Set base class variables.
   BaseClass::setThreadName("ExamQCall");
   BaseClass::setThreadPrintLevel(0);
   BaseClass::setThreadPriority(Ris::Threads::gPriorities.mTimerTest);
   BaseClass::mTimerPeriod = 1000;

   // Initialize qcalls.
   mExample1QCall.bind(this, &ExamQCallThread::executeExample1);
}

ExamQCallThread::~ExamQCallThread()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void ExamQCallThread::threadInitFunction()
{
   Prn::print(Prn::View21, "ExamQCallThread::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void  ExamQCallThread::threadExitFunction()
{
   Prn::print(Prn::View21, "ExamQCallThread::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer.

void ExamQCallThread::executeOnTimer(int aTimerCount)
{
   Prn::print(Prn::View21, "ExamQCallThread::executeOnTimer  %10d", aTimerCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// QCall registered to the mUdpMsgThread child thread. It is invoked when
// a message is received. It process the received messages.

void ExamQCallThread::executeExample1(int aCount)
{
   Prn::print(Prn::View21, "ExamQCallThread::executeExample1 ************************ %10d", aCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace