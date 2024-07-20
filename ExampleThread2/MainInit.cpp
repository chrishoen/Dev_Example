#include "stdafx.h"

#include "risThreadsThreads.h"
#include "someExampleParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize program resources.

void main_initialize(int argc,char** argv)
{
   printf("ExampleThread2 Program********************************************BEGIN\n");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************

   // Read parameters files.
   Some::gExampleParms.reset();
   Some::gExampleParms.readSection("default");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize print facility.

   // Initialize print.
   Prn::resetPrint();
   if (Some::gExampleParms.mPrintViewEnable)
   {
      // Initialize print with consoles.
      Prn::resetPrint(Some::gExampleParms.mPrintViewIPAddress);
      Prn::useConsole(1);
      Prn::useConsole(2);
      Prn::initializePrint();

      // Initialize print filters.
      Prn::setFilter(Prn::View11, true, 1);
      Prn::setFilter(Prn::View12, false, 1);
      Prn::setFilter(Prn::View21, true, 2);
      Prn::setFilter(Prn::View22, false, 2);
   }
   else
   {
      // Initialize print.
      Prn::resetPrint();
      Prn::initializePrint();

      // Initialize print filters.
      Prn::setFilter(Prn::View11, true);
      Prn::setFilter(Prn::View12, false);
      Prn::setFilter(Prn::View21, true);
      Prn::setFilter(Prn::View22, false);
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize program resourcs.

void main_finalize()
{
   // Finalize print facility.
   Prn::finalizePrint();

   printf("ExampleThread2 Program********************************************END\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
