#pragma once

/*==============================================================================
Example twothread.
==============================================================================*/
//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "risThreadsTwoThread.h"

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

class TwoThread1 : public Ris::Threads::BaseTwoThread
{
public:
   typedef Ris::Threads::BaseTwoThread BaseClass;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Infastructure:

   // Constructor.
   TwoThread1();

   // Thread init function. This is called by the base class immedidately 
   // after the thread starts running.
   void threadInitFunction() override;

   // Thread exit function. This is called by the base class immedidately
   //  before the thread is terminated.
   void threadExitFunction() override;

   // Execute periodically. This is called by the base class timer.
   void executeOnTimer(int aTimerCount) override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods: QCalls: These are used to send commands to the thread.

   // Execute an example action. This is passed an example variable. 

   // The qcall. This is a call that is queued to this thread.
   Ris::Threads::QCall1<int> mDoSomething1QCall;

   // Execute the call in the context of this thread.
   void executeDoSomething1(int aCode);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods: QCalls: These are used to send commands to the thread.

   // Execute an example action. This is passed an example variable. 

   // The qcall. This is a call that is queued to this thread.
   Ris::Threads::QCall1<int> mDoSomething2QCall;

   // Execute the call in the context of this thread.
   void executeDoSomething2(int aCode);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.
   
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance
       
#ifdef _SOMETWOTHREAD1_CPP_
          TwoThread1* gTwoThread1;
#else
   extern TwoThread1* gTwoThread1;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
