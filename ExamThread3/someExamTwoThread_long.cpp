/*==============================================================================
Detestion:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "someExamParms.h"
#include "someExamQCallThread.h"

#include "someExamTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run sequence qcall function. Execute an infinite loop sequence that
// sends a request to the slave, waits for the response, and processes it.
// It calls one of the process subroutines, based on the state. It executes
// in the context of the long thread. The purpose of this is to provide
// long thread execution context for message processing.

void ExamTwoThread::executeRunSeq1()
{
   Prn::print(0, "ExamTwoThread::executeRunSeq1 BEGIN");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Do this first.

   // Initialize the synchronization objects.
   mSeqWaitable.initialize(gExamParms.mTimerPeriod);
   mNotify.reset();

   // Reset variables. 
   resetVars();

   try
   {
      // Seq to transmit and receive messages.
      while (true)
      {
         //*********************************************************************
         //*********************************************************************
         //*********************************************************************
         // Wait.

         // If true then there was a serial timeout.
         bool tTimeoutFlag = false;

         // If true then there was a processing error.
         bool tProcErrorFlag = false;

         // Wait for timer or abort.
         mSeqWaitable.waitForTimerOrSemaphore();

         // Test for an abort
         if (mSeqWaitable.wasSemaphore()) throw 668;

         //*********************************************************************
         //*********************************************************************
         //*********************************************************************
         // Send a request to the slave, wait for the response and process it.

         try
         {
            // Default. This will be set by the specific subfunction.
            mSeqExitCode = cSeqExitNormal;

            // Test for a notification exception.
            // This can throw an execption if there's an abort.
            mNotify.testException();

            // Set the thread notification mask.
            mNotify.setMaskOne("RxMsg", cRxMsgNotifyCode);

            // Invoke the qcall thread request qcall.
            gExamQCallThread->mRxRequestQCall(mTxCount++);

         }
         catch (int aException)
         {
            if (aException == Ris::Threads::Notify::cTimeoutException)
            {
               Prn::print(0, "EXCEPTION ExamTwoThread::doProcess TIMEOUT %d", aException);

               // Rx timeout.
               tTimeoutFlag = true;

               // There was a processing error.
               tProcErrorFlag = true;
            }
            else if (aException == cSeqExitError)
            {
               Prn::print(0, "EXCEPTION ExamTwoThread::doProcess ERROR %d", aException);

               // There was a processing error.
               tProcErrorFlag = true;
            }
            else
            {
               Prn::print(0, "EXCEPTION ExamTwoThread::doProcess %d %s", aException, mNotify.mException);

               // There was a processing error.
               tProcErrorFlag = true;
            }
         }

         //*********************************************************************
         //*********************************************************************
         //*********************************************************************
         // Check errors.
         
         if (tProcErrorFlag)
         {
         }

         //*********************************************************************
         //*********************************************************************
         //*********************************************************************
         // Events.

         // Test for a timeout.
         if (tTimeoutFlag)
         {
         }
      }
   }
   catch (int aException)
   {
      if (aException == 668)
      {
         Prn::print(0, "EXCEPTION ExamTwoThread::executeRunSeq1 ABORT %d %s", aException, mNotify.mException);
         mSeqExitCode = cSeqExitAborted;
      }
      else
      {
         Prn::print(0, "EXCEPTION ExamTwoThread::executeRunSeq1 %d", aException);
         mSeqExitCode = cSeqExitError;
      }
   }
   catch (...)
   {
      Prn::print(0, "EXCEPTION ExamTwoThread::executeRunSeq1 UNKNOWN");
      mSeqExitCode = cSeqExitError;
   }

   // Finalize the synchronization objects.
   mSeqWaitable.finalize();
   mNotify.clearFlags();

   Prn::print(0, "ExamTwoThread::executeRunSeq1 END");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace