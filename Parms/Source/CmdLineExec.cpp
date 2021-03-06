
#include "prnPrint.h"
#include "my_functions.h"
#include "risPortableCalls.h"
#include "risCmdLineConsole.h"

#include "someExampleParms.h"
#include "someClass1.h"

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
   if(aCmd->isCmd("Run1"   ))  executeRun1(aCmd);
   if(aCmd->isCmd("GO1"    ))  executeGo1(aCmd);
   if(aCmd->isCmd("GO2"    ))  executeGo2(aCmd);
   if(aCmd->isCmd("GO3"    ))  executeGo3(aCmd);
   if(aCmd->isCmd("GO4"    ))  executeGo4(aCmd);
   if(aCmd->isCmd("GO5"    ))  executeGo5(aCmd);

   if(aCmd->isCmd("Parms"  ))  executeParms(aCmd);
   if(aCmd->isCmd("Parms2" ))  executeParms2(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeRun1(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,"Default");

   // Reset parms and read sections from parms file.
   Some::gExampleParms.reset();
   Some::gExampleParms.readSection(aCmd->argString(1));
   Some::gExampleParms.readSection(aCmd->argString(2));

   // Instantiate example class with parms and run an example action.
   Some::Class1 tClass1(Some::gExampleParms);
   tClass1.doRun1();
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
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,"something");

   // Show arguments.
   Prn::print(0,"Go2 %s %10.6f",aCmd->argString(1));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo3(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo4(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo5(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeParms(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,"Default");

   // Reset parms and read sections from parms file.
   Some::gExampleParms.reset();
   Some::gExampleParms.readSection(aCmd->argString(1));
   Some::gExampleParms.show();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeParms2(Ris::CmdLineCmd* aCmd)
{
   // Set defaults if no arguments were entered.
   aCmd->setArgDefault(1,"Default");
   aCmd->setArgDefault(2,"Override1");

   // Reset parms and read sections from parms file.
   Some::gExampleParms.reset();
   Some::gExampleParms.readSection(aCmd->argString(1));
   Some::gExampleParms.readSection(aCmd->argString(2));
   Some::gExampleParms.show();
}

