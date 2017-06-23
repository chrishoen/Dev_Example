#include <stdlib.h>
#include <stdio.h>

#include "MainInit.h"
#include "prnPrint.h"
#include "risCmdLineConsole.h"

#include "someTimerThread1.h"
#include "someQCallThread1.h"
#include "CmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize the program.

   main_initialize(argc,argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch the program threads.

   Some::gQCallThread1 = new Some::QCallThread1;
   Some::gQCallThread1->launchThread();

   Some::gTimerThread1 = new Some::TimerThread1;
   Some::gTimerThread1->launchThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Run the user command line executive, it returns when the user exits.

   CmdLineExec* tExec = new CmdLineExec;
   Ris::gCmdLineConsole.execute(tExec);
   delete tExec;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Shutdown the program threads.

   Some::gTimerThread1->shutdownThread();
   delete Some::gTimerThread1;

   Some::gQCallThread1->shutdownThread();
   delete Some::gQCallThread1;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Finalize the program.

   main_finalize();
   return 0;
}
