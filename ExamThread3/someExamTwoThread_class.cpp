/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExamParms.h"

#define  _SOMEEXAMTWOTHREAD_CPP_
#include "someExamTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor. True is tta, false is da.

ExamTwoThread::ExamTwoThread()
   : mResponseNotify(&mNotify, cResponseNotifyCode)
{
   using namespace std::placeholders;

   // Set base class thread variables.
   BaseClass::mShortThread->setThreadName("ExamShort");
   BaseClass::mLongThread->setThreadName("ExamLong");

   BaseClass::mShortThread->setThreadPriority(Cmn::gPriorities.mShort);
   BaseClass::mShortThread->setThreadPrintLevel(gExamParms.mPrintLevel);

   BaseClass::mLongThread->setThreadPriority(Cmn::gPriorities.mLong);
   BaseClass::mShortThread->setThreadPrintLevel(gExamParms.mPrintLevel);

   // Set base class call pointers.
   BaseClass::mShortThread->mThreadInitCallPointer = std::bind(&ExamTwoThread::threadInitFunction, this);
   BaseClass::mShortThread->mThreadExitCallPointer = std::bind(&ExamTwoThread::threadExitFunction, this);
   BaseClass::mShortThread->mThreadExecuteOnTimerCallPointer = std::bind(&ExamTwoThread::executeOnTimer, this, _1);

   // Set qcalls.
   mRunSeq1QCall.bind(this->mLongThread, this, &ExamTwoThread::executeRunSeq1);
   mRxResponseQCall.bind(this->mShortThread, this, &ExamTwoThread::executeRxResponse);
   mAbortQCall.bind(this->mShortThread, this, &ExamTwoThread::executeAbort);

   // Set member variables.
   resetVars();
}

void ExamTwoThread::resetVars()
{
   mSeqExitCode = 0;
   mTxCount = 0;
   mRxCount = 0;
   mSeqState = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// before the thread starts running.

void ExamTwoThread::threadInitFunction()
{
   // Launch the sequence qcall.
   mRunSeq1QCall();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function. This is called by the base class immediately 
// after  the thread starts running.

void ExamTwoThread::threadExitFunction()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread shutdown function. This shuts down the two threads.

void ExamTwoThread::shutdownThreads()
{
   // Abort the long thread.
   BaseClass::mNotify.abort();
   mSeqWaitable.postSemaphore();

   // Shutdown the two threads.
   BaseClass::shutdownThreads();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// The qcall function. Post to the waitable to abort the long thread
// qcall. Execute in the context of the short thread.

void ExamTwoThread::executeAbort()
{
   Prn::print(0, "ABORT>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

   // Abort the long thread.
   mSeqWaitable.postSemaphore();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace