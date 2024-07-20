/*==============================================================================
Detestion:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "someExampleParms.h"
#include "someExampleQCallThread.h"

#include "someExampleTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run sequence qcall function. This is bound to the qcall. Execute an
// infinite loop sequence that sends a request to the slave, waits for the
// response, and processes it. It executes in the context of the long
// thread. The purpose of this is to provide long thread execution context
// for message processing.

void ExampleTwoThread::executeRunSeq1()
{
   Prn::print(0, "ExampleTwoThread::executeRunSeq1 BEGIN");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Do this first.

   // Reset variables. 
   resetVars();

   // Initialize the synchronization objects.
   mSeqWaitable.initialize(gExampleParms.mTimerPeriod);

   // Seq to transmit and receive messages.
   while (true)
   {
      //*********************************************************************
      //*********************************************************************
      //*********************************************************************
      // Wait for timer.

      // Wait for timer or abort.
      mSeqWaitable.waitForTimerOrSemaphore();

      // Test for an abort.
      if (mSeqWaitable.wasSemaphore())
      {
         Prn::print(0, "ExampleTwoThread::executeRunSeq1 abort1");
         break;
      }

      //*********************************************************************
      //*********************************************************************
      //*********************************************************************
      // Send a request to the slave, wait for the response and process it.

      // Restart the notification.
      BaseClass::mNotify.restart(false);

      // Invoke the qcall thread request qcall. The qcall thread will
      // invoke the short thread response qcall after a delay.
      Prn::print(Prn::Show1, "ExampleTwoThread::executeRunSeq1 send request ******************");
      gExampleQCallThread->mRequestQCall(mTxCount++);

      // Wait for response notification or abort from the short thread.
      BaseClass::mNotify.wait(gExampleParms.mTimeout1);

      // Test for timeout.
      if (mNotify.mTimeoutFlag)
      {
         Prn::print(0, "ExampleTwoThread::executeRunSeq1 timeout");
         break;
      }

      // Test for abort.
      if (BaseClass::mNotify.mAbortFlag)
      {
         Prn::print(0, "ExampleTwoThread::executeRunSeq1 abort2");
         break;
      }

      // Process the response.
      Prn::print(Prn::Show1, "ExampleTwoThread::executeRunSeq1 received response");
   }

   // Finalize the synchronization objects.
   mSeqWaitable.finalize();

   Prn::print(0, "ExampleTwoThread::executeRunSeq1 END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace