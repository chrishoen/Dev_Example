#pragma once

/*==============================================================================
Example timer thread.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "risThreadsTimerThread.h"

namespace Some
{
//******************************************************************************
//******************************************************************************
//******************************************************************************
// This is an example timer thread. It inherits from the timer thread base
// class. It executes a function periodically that invokes the example qcall
// thread qcall.

class ExamTimerThread : public Ris::Threads::BaseTimerThread
{
public:
   typedef Ris::Threads::BaseTimerThread BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   ExamTimerThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods. Thread base class overloads.

   // Execute periodically. This is called by the base class timer. It
   // invokes the example qcall thread qcall.
   void executeOnTimer(int aTimeCount) override;
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance.

#ifdef _SOMEXAMTIMERTHREAD_CPP_
         ExamTimerThread* gExamTimerThread = 0;
#else
   extern ExamTimerThread* gExamTimerThread;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


