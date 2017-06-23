#include "prnPrint.h"
#include "my_functions.h"
#include "risPortableCalls.h"
#include "risCmdLineConsole.h"

#include "someQCallThread1.h"

#include "CmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

CmdLineExec::CmdLineExec()
{
}

void CmdLineExec::reset()
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
   if(aCmd->isCmd("RESET"  ))  reset();

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

void CmdLineExec::executeDo2(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1,101);

   int tCode = aCmd->argInt(1);

   Some::gQCallThread1->mDoSomething2QCall(tCode);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1,10);
   aCmd->setArgDefault(2,11.1);

   int    tInt    = aCmd->argInt(1);
   double tDouble = aCmd->argDouble(2);

   Prn::print(0,"Show2 %d %10.6f",tInt,tDouble);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
}

