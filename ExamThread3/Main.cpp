#include "stdafx.h"

#include "risThreadsProcess.h"
#include "MainInit.h"
#include "risCmdLineConsole.h"
#include "CmdLineExec.h"

#include "someExamTwoThread.h"
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

   Some::gExamTwoThread = new Some::ExamTwoThread;
   Some::gExamTwoThread->launchThreads();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Show program threads.

   Ris::Threads::showCurrentThreadInfo();
   if (Some::gExamTwoThread)   Some::gExamTwoThread->showThreadInfo();
   if (Some::gExamQCallThread) Some::gExamQCallThread->showThreadInfo();

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

   if (Some::gExamTwoThread)   Some::gExamTwoThread->shutdownThreads();
   if (Some::gExamQCallThread) Some::gExamQCallThread->shutdownThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Delete program threads.

   if (Some::gExamTwoThread)
   {
      delete Some::gExamTwoThread;
      Some::gExamTwoThread = 0;
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
