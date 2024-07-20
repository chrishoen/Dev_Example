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
// This is an example program that has a timer thread that sends a qcall
// to a qcall thread.

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize program resources.

   main_initialize(argc, argv);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Launch program threads.

   if (true)
   {
      Some::gExampleQCallThread = new Some::ExampleQCallThread;
      Some::gExampleQCallThread->launchThread();
   }

   if (true)
   {
      Some::gExampleTimerThread = new Some::ExampleTimerThread;
      Some::gExampleTimerThread->launchThread();
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gExampleTimerThread) Some::gExampleTimerThread->showThreadInfo();
   if (Some::gExampleQCallThread) Some::gExampleQCallThread->showThreadInfo();

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

   if (Some::gExampleTimerThread)
   {
      Some::gExampleTimerThread->shutdownThread();
      delete Some::gExampleTimerThread;
      Some::gExampleTimerThread = 0;
   }

   if (Some::gExampleQCallThread)
   {
      Some::gExampleQCallThread->shutdownThread();
      delete Some::gExampleQCallThread;
      Some::gExampleQCallThread = 0;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Finalize program resources.

   main_finalize();
   return 0;
}
