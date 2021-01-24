#include "stdafx.h"

#include "risThreadsProcess.h"
#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

#include "someExamTimerThread.h"
#include "someExamQCallThread.h"

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

   Some::gExamQCallThread = new Some::ExamQCallThread;
   Some::gExamQCallThread->launchThread();

   Some::gExamTimerThread = new Some::ExamTimerThread;
   Some::gExamTimerThread->launchThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gExamTimerThread)    Some::gExamTimerThread->showThreadInfo();
   if (Some::gExamQCallThread)    Some::gExamQCallThread->showThreadInfo();

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

   if (Some::gExamTimerThread)     Some::gExamTimerThread->shutdownThread();
   if (Some::gExamQCallThread)     Some::gExamQCallThread->shutdownThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Delete program threads.

   if (Some::gExamTimerThread)
   {
      delete Some::gExamTimerThread;
      Some::gExamTimerThread = 0;
   }

   if (Some::gExamQCallThread)
   {
      delete Some::gExamQCallThread;
      Some::gExamQCallThread = 0;
   }

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // End program.

   main_finalize();
   return 0;
}
