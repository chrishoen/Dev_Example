//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#include "risCmdLineFile.h"
#include "risPortableCalls.h"


#define  _PROCOUDPPARMS_CPP_
#include "procoUdpParms.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

namespace ProtoComm
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

UdpParms::UdpParms()
{
   reset();
}

void UdpParms::reset()
{
   BaseClass::reset();
   BaseClass::setFilePath("files/ProtoComm_UdpParms.txt");

   mMyAppNumber = 0;

   strcpy(mMyUdpAddress, "0.0.0.0");
   mMyUdpPort = 0;
   mOtherUdpAddress[0]=0;
   mOtherUdpPort = 0;
   mUdpWrapFlag = false;
   mUdpBroadcast = false;

   mTraceLogEnable = false;
   mThreadTimerPeriod = 0;
   mNumWords = 0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Show.

void UdpParms::show()
{
   printf("\n");
   printf("UdpParms************************************************ %s\n", mTargetSection);

   printf("MyAppNumber             %-12d\n", mMyAppNumber);

   printf("MyUdpAddress            %-12s\n", mMyUdpAddress);
   printf("MyUdpPort               %-12d\n", mMyUdpPort);
   printf("OtherUdpAddress         %-12s\n", mOtherUdpAddress);
   printf("OtherUdpPort            %-12d\n", mOtherUdpPort);
   printf("UdpWrapflag             %-12s\n", my_string_from_bool(mUdpWrapFlag));
   printf("UdpBroadcast            %-12s\n", my_string_from_bool(mUdpBroadcast));

   printf("\n");
   printf("TraceLogEnable          %-12s\n", my_string_from_bool(mTraceLogEnable));
   printf("\n");
   printf("ThreadTimerPeriod       %-12d\n", mThreadTimerPeriod);
   printf("NumWords                %-12d\n", mNumWords);

   printf("UdpParms************************************************\n");
   printf("\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Base class override: Execute a command from the command file to set a 
// member variable.  Only process commands for the target section.This is
// called by the associated command file object for each command in the file.

void UdpParms::execute(Ris::CmdLineCmd* aCmd)
{
   if (!isTargetSection(aCmd)) return;

   if (aCmd->isCmd("MyAppNumber"))         mMyAppNumber = aCmd->argInt(1);

   if (aCmd->isCmd("MyUdpAddress"))        aCmd->copyArgString(1, mMyUdpAddress, cMaxStringSize);
   if (aCmd->isCmd("MyUdpPort"))           mMyUdpPort = aCmd->argInt(1);
   if (aCmd->isCmd("OtherUdpAddress"))     aCmd->copyArgString(1, mOtherUdpAddress,cMaxStringSize);
   if (aCmd->isCmd("OtherUdpPort"))        mOtherUdpPort = aCmd->argInt(1);
   if (aCmd->isCmd("UdpWrapFlag"))         mUdpWrapFlag = aCmd->argBool(1);
   if (aCmd->isCmd("UdpBroadcast"))        mUdpBroadcast = aCmd->argBool(1);

   if (aCmd->isCmd("TraceLogEnable"))      mTraceLogEnable = aCmd->argBool(1);
   if (aCmd->isCmd("ThreadTimerPeriod"))   mThreadTimerPeriod = aCmd->argInt(1);
   if (aCmd->isCmd("NumWords"))            mNumWords = aCmd->argInt(1);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Calculate expanded member variables. This is called after the entire
// section of the command file has been processed.

void UdpParms::expand()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace