#include "stdafx.h"

#include "risThreadsProcess.h"
#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

#include "someExampleTimerThread.h"
#include "someExampleQCallThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Begin program.

   main_initialize(argc, argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch program threads.

   Some::gExampleQCallThread = new Some::ExampleQCallThread;
   Some::gExampleQCallThread->launchThread();

   Some::gExampleTimerThread = new Some::ExampleTimerThread;
   Some::gExampleTimerThread->launchThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gExampleTimerThread)    Some::gExampleTimerThread->showThreadInfo();
   if (Some::gExampleQCallThread)    Some::gExampleQCallThread->showThreadInfo();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Execute console command line executive, wait for user to exit.

   CmdLineExec* tExec = new CmdLineExec;
   Ris::gCmdLineConsole.execute(tExec);
   delete tExec;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Shutdown program threads.

   if (Some::gExampleTimerThread)     Some::gExampleTimerThread->shutdownThread();
   if (Some::gExampleQCallThread)     Some::gExampleQCallThread->shutdownThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Delete program threads.

   if (Some::gExampleTimerThread)
   {
      delete Some::gExampleTimerThread;
      Some::gExampleTimerThread = 0;
   }

   if (Some::gExampleQCallThread)
   {
      delete Some::gExampleQCallThread;
      Some::gExampleQCallThread = 0;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // End program.

   main_finalize();
   return 0;
}
