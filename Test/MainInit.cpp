#include "stdafx.h"


#include "risThreadsProcess.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize

void main_initialize(int argc,char** argv)
{
   printf("Test*******************************************BEGIN\n");
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize.

   // Enter process.
   Ris::Threads::enterProcessHigh();

   // Initialize print facility
   Prn::resetPrint();
   Prn::initializePrint();

   // Initialize print filters
   Prn::setFilter(Prn::Show1, true);
   Prn::setFilter(Prn::Show2, false);
   Prn::setFilter(Prn::Show3, false);
   Prn::setFilter(Prn::Show4, false);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize

void main_finalize()
{
   // Close print
   Prn::finalizePrint();

   // Exit process
   Ris::Threads::exitProcess();
   printf("Test*******************************************END\n");
}

