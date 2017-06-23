//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "prnPrint.h"

#define  _SOMETWOTHREAD1_CPP_
#include "someTwoThread1.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

TwoThread1::TwoThread1()
{
   // Set base class thread priority
   BaseClass::setThreadPriorityHigh();

   // Set timer period
   BaseClass::mTimerPeriod = 1000;

   // Set qcall call pointers.
   mDoSomething1QCall.bind (this,&TwoThread1::executeDoSomething1);
   mDoSomething2QCall.bind (this,&TwoThread1::executeDoSomething2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread init function. This is called by the base class immedidately 
// after the thread starts running.

void TwoThread1::threadInitFunction()
{
   Prn::print(Prn::ProcInit1, "TwoThread1::threadInitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Thread exit function. This is called by the base class immedidately
//  before the thread is terminated.

void TwoThread1::threadExitFunction()
{
   Prn::print(Prn::ProcInit1, "TwoThread1::threadExitFunction");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute periodically. This is called by the base class timer.

void TwoThread1::executeOnTimer (int aTimeCount)
{
   Prn::print(Prn::ViewRun1, "QCallThread Timer          %4d",aTimeCount);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute an example action. This is passed an example variable. 

void TwoThread1::executeDoSomething1(int aCode)
{
   Prn::print(Prn::ViewRun3, "QCallThread Something1     %4d",aCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Execute an example action. This is passed an example variable. 

void TwoThread1::executeDoSomething2(int aCode)
{
   Prn::print(Prn::ViewRun3, "QCallThread Something2                        %4d",aCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace