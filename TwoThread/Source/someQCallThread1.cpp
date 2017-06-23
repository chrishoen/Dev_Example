//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "prnPrint.h"

#define  _SOMEQCALLTHREAD1_CPP_
#include "someQCallThread1.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

QCallThread1::QCallThread1()
{
   // Set base class thread priority
   BaseClass::setThreadPriorityHigh();

   // Disable the base class timer.
   BaseClass::mTimerExecuteFlag  = false;

   // Set qcall call pointers.
   mRequestSomething1QCall.bind (this,&QCallThread1::executeRequestSomething1);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immedidately 
// after the thread starts running.

void QCallThread1::threadInitFunction()
{
   Prn::print(Prn::ProcInit1, "QCallThread1::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function. This is called by the base class immedidately
//  before the thread is terminated.

void QCallThread1::threadExitFunction()
{
   Prn::print(Prn::ProcInit1, "QCallThread1::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute an example work request and send a notification when completed. 
// It is passed a wait time that is used to simulate some work and a
// notification.

void QCallThread1::executeRequestSomething1(
   int aWaitTime,
   Ris::Threads::TwoThreadNotify* aCompletionNotify)
{
   Prn::print(Prn::ViewRun1, "QCallThread Something1 BEGIN");

   // Wait for the wait time to simulate some work.
   BaseClass::threadSleep(aWaitTime);

   // Send a completion notification.
   if (aCompletionNotify)
   {
      aCompletionNotify->notify();
   }

   Prn::print(Prn::ViewRun1, "QCallThread Something1 END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace