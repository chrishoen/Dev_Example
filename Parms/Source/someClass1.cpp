/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "prnPrint.h"

#include "someClass1.h"

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************

Class1::Class1()
{
   reset();
}

Class1::Class1(ExampleParms& aParms)
{
   mP = aParms;
   reset();
}

void Class1::initialize(ExampleParms& aParms)
{
   mP = aParms;
   reset();
}

void Class1::reset()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run something.

void Class1::doRun1()
{
   Prn::print(0,"doRun1 %d",mP.mMaxX);
   Prn::print(0," ");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace