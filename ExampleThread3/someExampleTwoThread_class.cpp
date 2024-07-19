/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExampleParms.h"

#define  _SOMEEXAMPLETWOTHREAD_CPP_
#include "someExampleTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor. True is tta, false is da.

ExampleTwoThread::ExampleTwoThread()
{
   using namespace std::placeholders;

   // Set base class thread variables.
   BaseClass::mShortThread->setThreadName("ExampleShort");
   BaseClass::mLongThread->setThreadName("ExampleLong");

   BaseClass::mShortThread->setThreadPriority(Cmn::gPriorities.mMasterShort);

   BaseClass::mLongThread->setThreadPriority(Cmn::gPriorities.mMasterLong);

   // Set base class call pointers.
   BaseClass::mShortThread->mThreadInitCallPointer = std::bind(&ExampleTwoThread::threadInitFunction, this);
   BaseClass::mShortThread->mThreadExitCallPointer = std::bind(&ExampleTwoThread::threadExitFunction, this);
   BaseClass::mShortThread->mThreadExecuteOnTimerCallPointer = std::bind(&ExampleTwoThread::executeOnTimer, this, _1);

   // Set qcalls.
   mRunSeq1QCall.bind(this->mLongThread, this, &ExampleTwoThread::executeRunSeq1);
   mResponseQCall.bind(this->mShortThread, this, &ExampleTwoThread::executeResponse);
   mAbortQCall.bind(this->mShortThread, this, &ExampleTwoThread::executeAbort);

   // Set member variables.
   resetVars();
}

void ExampleTwoThread::resetVars()
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

void ExampleTwoThread::threadInitFunction()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function. This is called by the base class immediately 
// after  the thread starts running.

void ExampleTwoThread::threadExitFunction()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread shutdown function. This shuts down the two threads.

void ExampleTwoThread::shutdownThreads()
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

void ExampleTwoThread::executeAbort()
{
   Prn::print(0, "ABORT>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

   // Abort the long thread.
   mSeqWaitable.postSemaphore();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace