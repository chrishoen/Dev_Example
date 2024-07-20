#include "stdafx.h"

#include "risThreadsProcess.h"
#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

#include "someExampleTwoThread.h"
#include "someExampleQCallThread.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This program contains a twothread and a qcall thread. The twothread
// sends a request qcall to the qcall thread and waits for a response.

int main(int argc,char** argv)
{
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Begin program.

   main_initialize();

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
      Some::gExampleTwoThread = new Some::ExampleTwoThread;
      Some::gExampleTwoThread->launchThreads();
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gExampleTwoThread)   Some::gExampleTwoThread->showThreadInfo();
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

   if (Some::gExampleTwoThread)
   {
      Some::gExampleTwoThread->shutdownThreads();
      delete Some::gExampleTwoThread;
      Some::gExampleTwoThread = 0;
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
   // End program.

   main_finalize();
   return 0;
}
