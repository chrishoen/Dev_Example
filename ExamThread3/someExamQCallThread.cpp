/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include "cmnPriorities.h"
#include "someExamParms.h"
#include "someExamTwoThread.h"

#define  _SOMEEXAMQCALLTHREAD_CPP_
#include "someExamQCallThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExamQCallThread::ExamQCallThread()
{
   // Set base class variables.
   BaseClass::setThreadName("ExamQCall");
   BaseClass::setThreadPrintLevel(gExamParms.mPrintLevel);
   BaseClass::setThreadPriority(Cmn::gPriorities.mQCall);

   // Initialize qcalls.
   mRxRequestQCall.bind(this, &ExamQCallThread::executeRxRequest);
}

ExamQCallThread::~ExamQCallThread()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immediately 
// after the thread starts running.

void ExamQCallThread::threadInitFunction()
{
   Prn::print(Prn::View21, "ExamQCallThread::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function, base class overload.

void  ExamQCallThread::threadExitFunction()
{
   Prn::print(Prn::View21, "ExamQCallThread::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Receive request qcall function. It is bound to the qcall. This is
// invoked by the example two thread to send a request to this thread.
// It sends a response back to the two thread.

void ExamQCallThread::executeRxRequest(int aCount)
{
   Prn::print(Prn::View21, "ExamQCallThread::executeRxRequest ************************ %10d", aCount);

   // Send a response back to the example two thread.
   gExamTwoThread->mRxResponseQCall(aCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace