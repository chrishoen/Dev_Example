
#include "prnPrint.h"
#include "risThreadsProcess.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize.

void main_initialize(int argc,char** argv)
{
   // Enter process.
   Ris::Threads::enterProcessHigh();

   // Initialize print facility.
   Prn::resetPrint();
   Prn::useConsole(1);
   Prn::useConsole(2);
   Prn::initializePrint();

   // Initialize print filters
   Prn::setFilter(Prn::ThreadRun1,  true);
   Prn::setFilter(Prn::ThreadRun2,  false);
   Prn::setFilter(Prn::ThreadRun3,  true);
   Prn::setFilter(Prn::ThreadRun4,  true);

   Prn::setFilter(Prn::ProcInit1,   true);
   Prn::setFilter(Prn::ProcInit2,   false);
   Prn::setFilter(Prn::ProcRun1,    true);
   Prn::setFilter(Prn::ProcRun2,    true);
   Prn::setFilter(Prn::ProcRun3,    false);
   Prn::setFilter(Prn::ProcRun4,    false);

   Prn::setFilter(Prn::ViewRun1,    true,  1);
   Prn::setFilter(Prn::ViewRun2,    false, 1);
   Prn::setFilter(Prn::ViewRun3,    true,  2);
   Prn::setFilter(Prn::ViewRun4,    false, 2);

   Prn::setFilter(Prn::QCallInit1, true);
   Prn::setFilter(Prn::QCallInit2, true);
   Prn::setFilter(Prn::QCallRun1, false);
   Prn::setFilter(Prn::QCallRun2, false);
   Prn::setFilter(Prn::QCallRun3, false);
   Prn::setFilter(Prn::QCallRun4, false);

   Prn::print(0,"QCallThread Program $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$BEGIN");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize.

void main_finalize()
{
   Prn::print(0,"QCallThread Program $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$END");

   // Close print facility.
   Prn::finalizePrint();

   // Exit process.
   Ris::Threads::exitProcess();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
