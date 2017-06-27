#pragma once

/*==============================================================================
Data  recording - Message helpers
==============================================================================*/

#include "defExampleDefs.h"
#include "exampleMsg.h"

namespace Example
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class provides a set of static helper functions for working with 
// messages.

class MsgHelper
{
public:

   // Initialize messages.
   static void initialize (TestMsg* aMsg);
   static void initialize (FirstMessageMsg* aMsg);
   static void initialize (SampleRecordMsg* aMsg);
   static void initialize (TimeSyncMsg* aMsg);
   static void initialize (FileHeaderMsg* aMsg);

   // Show messages.
   static void show (TestMsg* aMsg);
   static void show (FirstMessageMsg* aMsg);
   static void show (SampleRecordMsg* aMsg);
   static void show (TimeSyncMsg* aMsg);
   static void show (FileHeaderMsg* aMsg);

   // Copy messages and records.
   static void copyRecordToMsg (Def::SampleRecord* aRecord,SampleRecordMsg*   aMsg);
   static void copyMsgToRecord (SampleRecordMsg*   aMsg,   Def::SampleRecord* aRecord);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
