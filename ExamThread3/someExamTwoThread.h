#pragma once

/*==============================================================================
Example two thread.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsTwoThread.h"
#include "risThreadsWaitable.h"

namespace Some
{
 
//******************************************************************************
//******************************************************************************
//******************************************************************************
//
// The base comm thread has a member that is a ris serial string thread.
// This is used to send strings to the slave and receive strings from
// the slave. The serial thread sends received message strings to this
// thread via a ris qcall. The serial thread manages all of the message
// string crlf terminators.
//
// The base comm thread inherits from the ris base two thread class.
// This means that it has two threads: a long term thread and a short
// term thread. Both are ris qcall threads.
// 
// The long thread executes the sequence qcall and it provides the execution
// context for the message processing sequence. The sequence qcall is executed
// at initialization and contains an infinite sequence that processes the
// messages. The sequence only exits if it is aborted or the thread is
// terminated.
//
// The short thread executes ris qcalls sent by the ris serial receive 
// child thread. It validates received messages and notifies the long
// thread when messages are received. The long thread sends request
// messages and then waits for the notification from the short thread.
//
//******************************************************************************
//******************************************************************************
//******************************************************************************

class ExamTwoThread : public Ris::Threads::BaseTwoThread
{
public:
   typedef Ris::Threads::BaseTwoThread BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants:

   // Timer periods.
   static const int cSeqPeriod = 2000;

   // Wait timeouts.
   static const int cRxMsgTimeout = 2000;

   // Notification codes.
   static const int cRxMsgNotifyCode = 11;

   // Seq exit status codes.
   static const int cSeqExitNormal = 0;
   static const int cSeqExitAborted = 1;
   static const int cSeqExitError = 2;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Notifications.
   Ris::Threads::NotifyWrapper mRxMsgNotify;

   // Waitable timer.
   Ris::Threads::Waitable mSeqWaitable;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Process sequence exit code.
   int mSeqExitCode;

   // Seq state. Based on message bing processed.
   int mSeqState;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Metrics.
   int mTxCount;
   int mRxCount;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   ExamTwoThread();
   void resetVars();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. Thread base class overloads.

   // Thread init function. This is called by the base class immediately 
   // before the thread starts running.
   void threadInitFunction() override;

   // Thread exit function. This is called by the base class immediately 
   // after the thread starts running.
   void threadExitFunction() override;

   // Thread shutdown function. This shuts down the two threads.
   void shutdownThreads() override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. 

   // Receive response callback qcall.
   Ris::Threads::QCall1<int> mRxResponseQCall;

   // Receive response qcall function. It is bound to the qcall. This is
   // invoked by the example qcall thread after it receives a request qcall
   // from the long thread. It executes in the context of the short thread.
   // It notifies the long thread that a response was received.
   void executeRxResponse(int);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. qcalls.

   // Run sequence qcall. 
   Ris::Threads::QCall0 mRunSeq1QCall;

   // Run sequence qcall function. Execute an infinite loop sequence that
   // sends a request to the slave, waits for the response, and processes it.
   // It calls one of the process subroutines, based on the state. It executes
   // in the context of the long thread. The purpose of this is to provide
   // long thread execution context for message processing.
   void executeRunSeq1();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods: QCalls: These are used to send commands to the thread.

   // Abort a running sequence qcall.

   // The qcall. This is a call that is queued to this thread.
   Ris::Threads::QCall0 mAbortQCall;

   // The qcall function. Post to the waitable to abort the long thread
   // qcall. Execute in the context of the short thread.
   void executeAbort();

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global singular instance.

#ifdef _SOMEEXAMTWOTHREAD_CPP_
ExamTwoThread* gExamTwoThread = 0;
#else
extern ExamTwoThread* gExamTwoThread;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
