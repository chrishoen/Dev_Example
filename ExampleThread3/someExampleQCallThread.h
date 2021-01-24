#pragma once

/*==============================================================================
Exampleple qcall thread.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsQCallThread.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This is an example qcall thread. It inherits from BaseQCallThread to obtain
// a call queue based thread functionality.
//
// It is used in conjunction with the example two thread in a master/slave
// scheme. The two thread is a master that sends request qcalls to the slave
// qcall thread, who then sends response qcalls back to the master.

class  ExampleQCallThread : public Ris::Threads::BaseQCallThread
{
public:
   typedef Ris::Threads::BaseQCallThread BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   ExampleQCallThread();
  ~ExampleQCallThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. Thread base class overloads.

   // Thread init function. This is called by the base class immediately 
   // after the thread starts running.
   void threadInitFunction() override;

   // Thread exit function. This is called by the base class immediately
   // before the thread is terminated.
   void threadExitFunction() override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. 

   // Receive request callback qcall.
   Ris::Threads::QCall1<int> mRxRequestQCall;

   // Receive request qcall function. It is bound to the qcall. This is
   // invoked by the example two thread to send a request to this thread.
   // It sends a response back to the two thread.
   void executeRxRequest(int);

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global singular instance.

#ifdef _SOMEEXAMPLEQCALLTHREAD_CPP_
       ExampleQCallThread* gExampleQCallThread = 0;
#else
extern ExampleQCallThread* gExampleQCallThread;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
