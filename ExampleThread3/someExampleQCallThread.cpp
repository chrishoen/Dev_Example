/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExampleParms.h"
#include "someExampleTwoThread.h"

#define  _SOMEEXAMPLEQCALLTHREAD_CPP_
#include "someExampleQCallThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExampleQCallThread::ExampleQCallThread()
{
   // Set base class variables.
   BaseClass::setThreadName("ExampleQCall");
   BaseClass::setThreadPriority(Cmn::gPriorities.mTest);

   // Initialize qcalls.
   mRequestQCall.bind(this, &ExampleQCallThread::executeRequest);
}

ExampleQCallThread::~ExampleQCallThread()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void ExampleQCallThread::threadInitFunction()
{
   Prn::print(Prn::Show1, "ExampleQCallThread::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void  ExampleQCallThread::threadExitFunction()
{
   Prn::print(Prn::Show1, "ExampleQCallThread::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Receive request qcall function. It is bound to the qcall. This is
// invoked by the example two thread to send a request to this thread.
// It sends a delayed response back to the two thread.

void ExampleQCallThread::executeRequest(int aCount)
{
   Prn::print(Prn::Show1, "ExampleQCallThread::executeRequest %10d", aCount);

   // Sleep.
   BaseClass::threadSleep(gExampleParms.mDelay1);

   // Send a response back to the example two thread.
   Prn::print(Prn::Show1, "ExampleQCallThread::executeRequest send response");
   gExampleTwoThread->mResponseQCall(aCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace