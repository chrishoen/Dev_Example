#include "prnPrint.h"
#include "my_functions.h"
#include "risPortableCalls.h"
#include "risCmdLineConsole.h"

#include "someTwoThread1.h"

#include "CmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

CmdLineExec::CmdLineExec()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class is the program command line executive. It processes user
// command line inputs and executes them. It inherits from the command line
// command executive base class, which provides an interface for executing
// command line commands. It provides an override execute function that is
// called by a console executive when it receives a console command line input.
// The execute function then executes the command.

void CmdLineExec::execute(Ris::CmdLineCmd* aCmd)
{
   if(aCmd->isCmd("DO1"    ))  executeDo1(aCmd);
   if(aCmd->isCmd("DO2"    ))  executeDo2(aCmd);

   if(aCmd->isCmd("GO1"    ))  executeGo1(aCmd);
   if(aCmd->isCmd("GO2"    ))  executeGo2(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeDo1(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,101);

   // Set variables from arguments.
   int tCode = aCmd->argInt(1);

   // Send qcall to the qcall thread, pass the variables.
   Some::gTwoThread1->mDoSomething1QCall(tCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeDo2(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,4000);

   // Set variables from arguments.
   int tWaitTime = aCmd->argInt(1);

   // Send qcall to the qcall thread, pass the variables.
   Some::gTwoThread1->mDoSomething2QCall(tWaitTime);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,10);
   aCmd->setArgDefault(2,11.1);

   // Set variables from arguments.
   int    tInt    = aCmd->argInt(1);
   double tDouble = aCmd->argDouble(2);

   // Show variables.
   Prn::print(0,"Show2 %d %10.6f",tInt,tDouble);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
}

