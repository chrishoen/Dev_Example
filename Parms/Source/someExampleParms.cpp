//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "my_functions.h"
#include "risCmdLineFile.h"
#include "risPortableCalls.h"
#include "dsp_math.h"

#define  _SOMEEXAMPLEPARMS_CPP_
#include "someExampleParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace Some
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

ExampleParms::ExampleParms()
{
   reset();
}

void ExampleParms::reset()
{
   BaseClass::reset();
   strcpy(BaseClass::mDefaultFileName, "Example_Parms.txt");

   mExampleType    = cNone;

   mExampleOrder = 0;
   mMaxX = 0;
   mMaxY = 0;
   mNumX = 0;
   mNumY = 0;
   mFilterX = 0;
   mFilterY = 0;

   mNeighborhoodSize = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Show.

void ExampleParms::show()
{
   printf("\n");
   printf("ExampleParms************************************************ %s\n", mTargetSection);

   printf("\n");
   printf("ExampleType            %10s\n",   asStringExampleType(mExampleType));

   printf("\n");
   printf("ExampleOrder           %10d\n",        mExampleOrder);
   printf("MaxXY                  %10d %10d\n",   mMaxX,mMaxY);
   printf("NumXY                  %10d %10d\n",   mNumX,mNumY);
   printf("FilterXY               %10d %10d\n",   mFilterX,mFilterY);

   printf("\n");
   printf("NeighborhoodSize       %10d\n",        mNeighborhoodSize);

   printf("\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class override: Execute a command from the command file to set a 
// member variable.  Only process commands for the target section.This is
// called by the associated command file object for each command in the file.

void ExampleParms::execute(Ris::CmdLineCmd* aCmd)
{
   if (!isTargetSection(aCmd)) return;

   if (aCmd->isCmd("ExampleOrder"))      mExampleOrder = aCmd->argInt(1);
   if (aCmd->isCmd("MaxXY"))
   {
      mMaxX = aCmd->argInt(1);
      mMaxY = aCmd->argInt(2);
   }

   if (aCmd->isCmd("NumXY"))
   {
      mNumX = aCmd->argInt(1);
      mNumY = aCmd->argInt(2);
   }

   if (aCmd->isCmd("FilterXY"))
   {
      mFilterX = aCmd->argInt(1);
      mFilterY = aCmd->argInt(2);
   }

   if (aCmd->isCmd("NeighborhoodSize"))   mNeighborhoodSize = aCmd->argInt(1);

   if (aCmd->isCmd("ExampleType"))
   {
      if (aCmd->isArgString(1,asStringExampleType(cExampleTestTable)))      mExampleType = cExampleTestTable;
      if (aCmd->isArgString(1,asStringExampleType(cExampleP3P1)))           mExampleType = cExampleP3P1;
      if (aCmd->isArgString(1,asStringExampleType(cExamplePNP)))            mExampleType = cExamplePNP;
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Calculate expanded member variables. This is called after the entire
// section of the command file has been processed.

void ExampleParms::expand()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

char* ExampleParms::asStringExampleType(int aX)
{
   switch (aX)
   {
   case cNone                 : return "None";
   case cExampleTestTable     : return "TestTable";
   case cExampleP3P1          : return "P3P1";
   case cExamplePNP           : return "PNP";
   default : return "UNKNOWN";
   }
}

char* ExampleParms::asStringExampleType()
{
   return asStringExampleType(mExampleType);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace