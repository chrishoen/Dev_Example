/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExampleParms.h"

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
   BaseClass::setThreadPriority(Cmn::gPriorities.mQCall);
   BaseClass::mTimerPeriod = gExampleParms.mTimerPeriod;

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
   Prn::print(Prn::View21, "ExampleQCallThread::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void  ExampleQCallThread::threadExitFunction()
{
   Prn::print(Prn::View21, "ExampleQCallThread::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer.

void ExampleQCallThread::executeOnTimer(int aTimerCount)
{
   Prn::print(Prn::View21, "ExampleQCallThread::executeOnTimer  %10d", aTimerCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// QCall registered to the mUdpMsgThread child thread. It is invoked when
// a message is received. It process the received messages.

void ExampleQCallThread::executeRequest(int aCount)
{
   Prn::print(Prn::View21, "ExampleQCallThread::executeRequest ************************ %10d", aCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace