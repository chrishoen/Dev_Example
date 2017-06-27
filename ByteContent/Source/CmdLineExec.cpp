
#include "prnPrint.h"
#include "my_functions.h"
#include "risPortableCalls.h"
#include "risCmdLineConsole.h"

#include "exampleMsg.h"
#include "exampleMsgHelper.h"

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
   if(aCmd->isCmd("GO1"    ))  executeGo1(aCmd);
   if(aCmd->isCmd("GO2"    ))  executeGo2(aCmd);
   if(aCmd->isCmd("GO3"    ))  executeGo3(aCmd);
   if(aCmd->isCmd("GO4"    ))  executeGo4(aCmd);
   if(aCmd->isCmd("GO5"    ))  executeGo5(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   // Allocate a byte buffer.
   Ris::ByteBuffer tBuffer(20000);

   // Message monkey.
   Example::MsgMonkey tMonkey;

   // Create a transmit message.
   Example::SampleRecordMsg* tTxMsg = new Example::SampleRecordMsg;
   Example::MsgHelper::initialize(tTxMsg);

   // Write the transmit message to the buffer.
   tMonkey.putMsgToBuffer(&tBuffer,tTxMsg);

   // Read a receive message from the buffer.
   Example::SampleRecordMsg* tRxMsg = 0;
   tRxMsg = (Example::SampleRecordMsg*)tMonkey.makeMsgFromBuffer(&tBuffer);

   // Show the receive message.
   Example::MsgHelper::show(tRxMsg);

   // Done.
   delete tTxMsg;
   delete tRxMsg;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
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

