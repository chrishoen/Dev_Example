/*==============================================================================
Detestion:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "someExamTwoThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Receive response qcall function. It is bound to the qcall. This is
// invoked by the example qcall thread after it receives a request qcall
// from the long thread. It executes in the context of the short thread.
// It notifies the long thread that a response was received.

void ExamTwoThread::executeRxResponse(int aCount)
{
   // Metrics.
   mRxCount++;

   Prn::print(Prn::View21, "ExamTwoThread::executeRxResponse %d", aCount);

   // Notify the long thread that a response was received.
   mNotify.notify(cRxMsgNotifyCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace