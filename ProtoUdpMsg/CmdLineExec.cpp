
#include "stdafx.h"

#include "procoUdpParms.h"
#include "procoMsg.h"
#include "procoMsgHelper.h"

#include "procoPeerThread.h"
#include "procoMonitorThread.h"

#include "CmdLineExec.h"

using namespace ProtoComm;

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

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
// the following specific command execution functions. This is called by
// the owner of this object to pass command line commands to it. 

void CmdLineExec::execute(Ris::CmdLineCmd* aCmd)
{
   if (aCmd->isCmd("TP"))        ProtoComm::gPeerThread->mTPCode = aCmd->argInt(1);
   if (aCmd->isCmd("SEND"))      executeSend(aCmd);
   if (aCmd->isCmd("ECHO"))      executeEcho(aCmd);
   if (aCmd->isCmd("DATA"))      executeData(aCmd);
   if (aCmd->isCmd("GO1"))       executeGo1(aCmd);
   if (aCmd->isCmd("GO2"))       executeGo2(aCmd);
   if (aCmd->isCmd("GO3"))       executeGo3(aCmd);
   if (aCmd->isCmd("GO4"))       executeGo4(aCmd);
   if (aCmd->isCmd("Parms"))     executeParms(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class override. Execute special command line command.
// A special command is one that consists of only a single digit
// "0" .. "9" followed by an enter.

void CmdLineExec::special(int aSpecial)
{
   ProtoComm::gPeerThread->mShowCode = aSpecial;
   ProtoComm::gMonitorThread->mShowCode = aSpecial;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeSend (Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1,1);
   int tMsgType= aCmd->argInt(1);

   switch (tMsgType)
   {
      case 1:
      {
         ProtoComm::TestMsg* tMsg = new ProtoComm::TestMsg;
         MsgHelper::initialize(tMsg);
         gPeerThread->sendMsg(tMsg);
         break;
      }
      case 5:
      {
         ProtoComm::DataMsg* tMsg = new ProtoComm::DataMsg;
         MsgHelper::initialize(tMsg);
         gPeerThread->sendMsg(tMsg);
         break;
      }
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeEcho(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1, 0);
   int tNumWords = aCmd->argInt(1);
   
   ProtoComm::EchoRequestMsg* tMsg = new ProtoComm::EchoRequestMsg;
   MsgHelper::initialize(tMsg,tNumWords);
   gPeerThread->sendMsg(tMsg);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeData(Ris::CmdLineCmd* aCmd)
{
   ProtoComm::DataMsg* tMsg = new ProtoComm::DataMsg;
   MsgHelper::initialize(tMsg);

   gPeerThread->sendMsg(tMsg);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void test1(Ris::ByteContent* aMsg)
{
   ProtoComm::BaseMsg* tMsg = (ProtoComm::BaseMsg*)aMsg;
   Prn::print(0, "MessageType %d", tMsg->mMessageType);
}

void test2(Ris::ByteContent* aMsg)
{
   test1(aMsg);
}

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   ProtoComm::TestMsg* tMsg = new ProtoComm::TestMsg;
   test1(tMsg);
   test2(tMsg);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
   ProtoComm::MsgMetrics tMsgMetrics;
   ProtoComm::TestMsg* tMsg = new ProtoComm::TestMsg;
   tMsgMetrics.updateAllVars(tMsg, 100);
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

void CmdLineExec::executeParms(Ris::CmdLineCmd* aCmd)
{
   ProtoComm::gUdpParms.show();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeHelp(Ris::CmdLineCmd* aCmd)
{
   Prn::print(0, "help *******************************************************");
   Prn::print(0, "");
   Prn::print(0, "send        -- send a test message ");
   Prn::print(0, "tp bool     -- enable/disable periodic sends");
   Prn::print(0, "echo        -- send echo request message");
   Prn::print(0, "data        -- send data message");
   Prn::print(0, "");
   Prn::print(0, "special commands 0..9");
   Prn::print(0, "0           -- don't show monitor");
   Prn::print(0, "1           -- show message metrics and counts");
   Prn::print(0, "2           -- show serial/socket message metrics");
   Prn::print(0, "");
   Prn::print(0, "parms       -- show program parms");
   Prn::print(0, "e           -- exit program");
   Prn::print(0, "");
   Prn::print(0, "trc help    -- show trace help");
}
//******************************************************************************
//******************************************************************************
//******************************************************************************

