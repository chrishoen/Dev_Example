#include <stdio.h>
#include <string.h>
#include "prnPrint.h"
#include "risProgramTime.h"
#include "risSystemTime.h"

#include "exampleMsgHelper.h"

namespace Example
{
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************

void MsgHelper::initialize(TestMsg* aMsg)
{
   aMsg->mCode1 = 101;
   aMsg->mCode2 = 102;
   aMsg->mCode3 = 103;
   aMsg->mCode4 = 104;
}

void MsgHelper::show(TestMsg* aMsg)
{
   Prn::print(Prn::ProcRun1, "TestMsg");
   Prn::print(Prn::ProcRun1, "Code1      %d", aMsg->mCode1);
   Prn::print(Prn::ProcRun1, "Code2      %d", aMsg->mCode2);
   Prn::print(Prn::ProcRun1, "Code3      %d", aMsg->mCode3);
   Prn::print(Prn::ProcRun1, "Code4      %d", aMsg->mCode4);
   Prn::print(Prn::ProcRun1, "");
}

//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************

void MsgHelper::initialize(FirstMessageMsg* aMsg)
{
   aMsg->mCode1 = 201;
}

void MsgHelper::show(FirstMessageMsg* aMsg)
{
   Prn::print(Prn::ProcRun1, "TestMsg");
   Prn::print(Prn::ProcRun1, "Code1      %d", aMsg->mCode1);
   Prn::print(Prn::ProcRun1, "");
}

//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************

void MsgHelper::initialize(SampleRecordMsg* aMsg)
{
   aMsg->mSensorId = 1;
   aMsg->mSeqNum   = 2;
   aMsg->mToa      = 1.0f;
   aMsg->mDeltaToa = .010f;
   aMsg->mTiltX    = 11.11f;
   aMsg->mTiltY    = 22.22f;
}

void MsgHelper::show(SampleRecordMsg* aMsg)
{
   Prn::print(Prn::ProcRun1, "SampleRecordMsg");

   Prn::print(Prn::ProcRun1, "SensorId           %10d",   aMsg-> mSensorId);
   Prn::print(Prn::ProcRun1, "SeqNum             %10d",   aMsg-> mSeqNum);
   Prn::print(Prn::ProcRun1, "Toa                %10.4f", aMsg-> mToa);
   Prn::print(Prn::ProcRun1, "DeltaToa           %10.4f", aMsg-> mDeltaToa);
   Prn::print(Prn::ProcRun1, "TiltX              %10.4f", aMsg-> mTiltX);
   Prn::print(Prn::ProcRun1, "TiltY              %10.4f", aMsg->mTiltY);

   Prn::print(Prn::ProcRun1, "");
}

void MsgHelper::copyMsgToRecord(SampleRecordMsg* aMsg, Def::SampleRecord* aRecord)
{
   aRecord->mSensorId    = aMsg->mSensorId;
   aRecord->mSeqNum      = aMsg->mSeqNum;
   aRecord->mToa         = aMsg->mToa;
   aRecord->mDeltaToa    = aMsg->mDeltaToa;
   aRecord->mTiltX       = aMsg->mTiltX;
   aRecord->mTiltY       = aMsg->mTiltY;
}

void MsgHelper::copyRecordToMsg(Def::SampleRecord* aRecord,SampleRecordMsg* aMsg)
{
   aMsg->mSensorId    = (unsigned int)aRecord->mSensorId;
   aMsg->mSeqNum      = (unsigned int)aRecord->mSeqNum & 0x7FFFFFFF;
   aMsg->mToa         = (float)aRecord->mToa;
   aMsg->mDeltaToa    = (float)aRecord->mDeltaToa;
   aMsg->mTiltX       = (float)aRecord->mTiltX;
   aMsg->mTiltY       = (float)aRecord->mTiltY;
}

//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************
//****************************************************************************

void MsgHelper::initialize(TimeSyncMsg* aMsg)
{
   aMsg->mProgramTime = 1.1;
   aMsg->mProgramTime = Ris::getCurrentProgramTime();
}

void MsgHelper::show(TimeSyncMsg* aMsg)
{
   char tString[100];

   Prn::print(Prn::ProcRun1, "TimeSyncMsg");
   Prn::print(Prn::ProcRun1, "ProgramTime        %10.4f", aMsg-> mProgramTime);
   Prn::print(Prn::ProcRun1, "SystemTime             %s",Ris::getSystemTimeAsString1(&aMsg->mSystemTime,tString,0,0));
   Prn::print(Prn::ProcRun1, "");
}

//****************************************************************************
//****************************************************************************
//****************************************************************************

void MsgHelper::initialize(FileHeaderMsg* aMsg)
{
   aMsg->mFirstToa     = 0.111;
   aMsg->mLastToa     = 0.222;
   aMsg->mDurationToa = 0.333;
   aMsg->mSampleCount = 404;

   aMsg->mCreateProgramTime = Ris::getCurrentProgramTime();
   aMsg->mCloseProgramTime = Ris::getCurrentProgramTime();
   GetSystemTime(&aMsg->mCreateSystemTime);
   GetSystemTime(&aMsg->mCloseSystemTime);
}

void MsgHelper::show(FileHeaderMsg* aMsg)
{
   char tString[100];

   Prn::print(Prn::ProcRun1, "");
   Prn::print(Prn::ProcRun1, "FileHeaderMsg");

   Prn::print(Prn::ProcRun1, "HeaderState        %10d",   aMsg-> mHeaderState);
   Prn::print(Prn::ProcRun1, "SampleCount        %10d",   aMsg-> mSampleCount);
   Prn::print(Prn::ProcRun1, "JointCode          %10d",   aMsg-> mJointCode);

   Prn::print(Prn::ProcRun1, "CreateSystemTime       %s",Ris::getSystemTimeAsString1(&aMsg->mCreateSystemTime,tString,0,0));
   Prn::print(Prn::ProcRun1, "CloseSystemTime        %s",Ris::getSystemTimeAsString1(&aMsg->mCloseSystemTime,tString,0,0));
   Prn::print(Prn::ProcRun1, "CreateProgramTime  %10.4f", aMsg-> mCreateProgramTime);
   Prn::print(Prn::ProcRun1, "CloseProgramTime   %10.4f", aMsg-> mCloseProgramTime);

   Prn::print(Prn::ProcRun1, "FirstToa           %10.4f", aMsg-> mFirstToa);
   Prn::print(Prn::ProcRun1, "LastToa            %10.4f", aMsg-> mLastToa);
   Prn::print(Prn::ProcRun1, "DurationToa        %10.4f", aMsg-> mDurationToa);
}


//****************************************************************************
//****************************************************************************
//****************************************************************************
}//namespace
