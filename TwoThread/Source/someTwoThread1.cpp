//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "prnPrint.h"

#include "someQCallThread1.h"

#define  _SOMETWOTHREAD1_CPP_
#include "someTwoThread1.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

TwoThread1::TwoThread1()
{
   // Set base class thread priority
   BaseClass::mShortThread->setThreadPriorityHigh();
   BaseClass::mLongThread->setThreadPriorityLow();

   // Set timer period
   BaseClass::mShortThread->mTimerPeriod = 1000;

   // Set call pointers
   BaseClass::mShortThread->mThreadInitCallPointer.bind(this, &TwoThread1::threadInitFunction);
   BaseClass::mShortThread->mThreadExitCallPointer.bind(this, &TwoThread1::threadExitFunction);
   BaseClass::mShortThread->mThreadExecuteOnTimerCallPointer.bind(this, &TwoThread1::executeOnTimer);

   // Set qcall call pointers.
   mDoSomething1QCall.bind (this->mLongThread,this,&TwoThread1::executeDoSomething1);
   mDoSomething2QCall.bind (this->mLongThread,this,&TwoThread1::executeDoSomething2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immedidately 
// after the thread starts running.

void TwoThread1::threadInitFunction()
{
   Prn::print(Prn::ProcInit1, "TwoThread1::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function. This is called by the base class immedidately
//  before the thread is terminated.

void TwoThread1::threadExitFunction()
{
   Prn::print(Prn::ProcInit1, "TwoThread1::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer.

void TwoThread1::executeOnTimer (int aTimeCount)
{
   Prn::print(Prn::ViewRun3, "TwoThread Timer          %4d",aTimeCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute an example action. This is passed an example variable. 

void TwoThread1::executeDoSomething1(int aCode)
{
   Prn::print(Prn::ViewRun1, "QCallThread Something1     %4d",aCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute an example action. This is passed an example variable. 

void TwoThread1::executeDoSomething2(int aWaitTime)
{
   Prn::print(Prn::ViewRun1, "TwoThread::executeDoSomething2>>>>>>>>>>>END");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Execute example sequence: send a command to the qcall thread and wait
   // for a response.

   try
   {
      //************************************************************************
      //************************************************************************
      //************************************************************************
      // Locals.

      // Completion notification.
      Ris::Threads::TwoThreadNotify tNotify(this, 1);

      //************************************************************************
      //************************************************************************
      //************************************************************************
      // Show the target reference image.

      // Reset thread notifications.
      BaseClass::resetNotify();
           
      // Send a work request to the qcall thread.
      gQCallThread1->mRequestSomething1QCall(aWaitTime,&tNotify);

      // Wait for the notification, ten second timeout.
      BaseClass::waitForNotify(10000,1);
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // If the preceding code section encountered errors or timeouts then 
   // this section executes. 

   catch (int aStatus)
   {
      Prn::print(Prn::ViewRun1, "Exception TwoThread::executeDoSomething2  ERROR %d",aStatus);

      // Exit.
      return;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Done. 

   Prn::print(Prn::ViewRun1, "TwoThread::executeDoSomething2<<<<<<<<<<<END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace