/*==============================================================================
Detestion:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "someExampleTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Receive response qcall function. It is bound to the qcall. This is
// invoked by the example qcall thread after it receives a request qcall
// from the long thread. It executes in the context of the short thread.
// It notifies the long thread that a response was received.

void ExampleTwoThread::executeResponse(int aCount)
{
   // Metrics.
   mRxCount++;

   Prn::print(Prn::View21, "ExampleTwoThread::executeResponse %d", aCount);

   // Notify the long thread that a response was received.
   mNotify.notify();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace