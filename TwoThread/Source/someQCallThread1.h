#ifndef _SOMEQCALLTHREAD1_H_
#define _SOMEQCALLTHREAD1_H_

/*==============================================================================
Example qcall thread.
==============================================================================*/
//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsTwoThread.h"
#include "risThreadsQCallThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class is an example qcall thread. It inherits from the base qcall
// thread to obtain qcall processing capability and a periodic timer.
//
// it executes a qcall that is sent by the timer thread.
//
// It executes periodically according to its own thread timer.

class QCallThread1 : public Ris::Threads::BaseQCallThread
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
   // Intrastructure:

   // Constructor.
   QCallThread1();

   // Thread init function. This is called by the base class immedidately 
   // after the thread starts running.
   void threadInitFunction() override;

   // Thread exit function. This is called by the base class immedidately
   //  before the thread is terminated.
   void threadExitFunction() override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods: QCalls: These are used to send commands to the thread.

   // Execute an example work request and send a notification when completed. 
   // It is passed a wait time that is used to simulate some work and a
   // notification.

   // The qcall. This is a call that is queued to this thread.
   Ris::Threads::QCall2<int,Ris::Threads::TwoThreadNotify*> mRequestSomething1QCall;

   // Execution for the qcall.
   void executeRequestSomething1(
      int aWaitTime,
      Ris::Threads::TwoThreadNotify* aCompletionNotify);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.
   
};

//******************************************************************************
// Global instance
       
#ifdef _SOMEQCALLTHREAD1_CPP_
          QCallThread1* gQCallThread1;
#else
   extern QCallThread1* gQCallThread1;
#endif

//******************************************************************************
}//namespace


#endif

