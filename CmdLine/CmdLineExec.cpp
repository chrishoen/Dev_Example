#include "stdafx.h"

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
// Base class override. Execute a command line command. It calls one of
// the following specific command execution functions.

void CmdLineExec::execute(Ris::CmdLineCmd* aCmd)
{
   if (aCmd->isCmd("GO1"))    executeGo1(aCmd);
   if (aCmd->isCmd("GO2"))    executeGo2(aCmd);
   if (aCmd->isCmd("GO3"))    executeGo3(aCmd);
   if (aCmd->isCmd("GO4"))    executeGo4(aCmd);
   if (aCmd->isCmd("GO5"))    executeGo5(aCmd);
   if (aCmd->isCmd("GO6"))    executeGo6(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Enter "go1 99".

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   // Set argument defaults. Try entering "go1".
   aCmd->setArgDefault(1, 101);

   // Get variables from command line arguments.
   int tInteger = aCmd->argInt(1);

   // Show variables.
   Prn::print(0, "Integer   %d", tInteger);
   Prn::print(0, "");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Enter "go1 11 12.34 abcdefgh".

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
   // Set argument defaults. Try entering "go2".
   aCmd->setArgDefault(1, 101);
   aCmd->setArgDefault(2, 102.34);
   aCmd->setArgDefault(3, "aaaa");

   // Get variables from command line arguments.
   int tInteger = aCmd->argInt(1);
   double tDouble = aCmd->argDouble(2);
   char tString[100];
   aCmd->copyArgString(3, tString, 99);

   // Show variables.
   Prn::print(0, "Integer   %d", tInteger);
   Prn::print(0, "Double    %.3f", tDouble);
   Prn::print(0, "String    %s", tString);
   Prn::print(0, "");
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
   printf("printf\n");
   Prn::print(0, "Prn::print 0");
   Prn::print(Prn::Show1, "Prn::print Prn::Show1");
   Prn::print(Prn::Show2, "Prn::print Prn::Show");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo6(Ris::CmdLineCmd* aCmd)
{
}

