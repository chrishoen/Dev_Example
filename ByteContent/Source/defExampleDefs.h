#pragma once

/*==============================================================================
// Das common definitions
==============================================================================*/

#include "risThreadsQCall.h"  

namespace Def
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constants

static const int cNone    = 0;
static const int cSensorH = 1;
static const int cSensorA = 2;
static const int cSensorB = 3;

char* asStringSensor (int aX);

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class contains a set of sensor connection status flags.

class SensorStatus
{
public:
   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members:

   // If true then the sensor tcp connection has been established. These
   // reflect the sensor thread connection flags.
   bool mHConnectionFlag;
   bool mAConnectionFlag;
   bool mBConnectionFlag;

   //***************************************************************************
   // All connected.

   // True if all of the sensors that are enabled are connected.
   bool mAllConnectedFlag;

   // True if the last session change caused the all flag to change.
   bool mAllConnectedChangeFlag;

   // Last value of the above variable.
   bool mLastAllConnectedFlag;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constructor.

   SensorStatus();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods:

   // Put a sensor session change event. Update the status logic variables.
   void putSessionChange(int aSensorId, bool aConnectionFlag);

};

//***************************************************************************
//***************************************************************************
//***************************************************************************
//***************************************************************************
//***************************************************************************
//***************************************************************************
// Sensor input sample record. This contains raw sensor inputs and time of
// arrival. It is updated at the sampling rate of 100 hz.

class SampleRecord
{
public:

   //***********************************************************************
   // Members

   int    mSensorId;    // Identifier.
   int    mSeqNum;      // Record sequence number 0..65536.  

   double mToa;         // Time of arrival of sensor input.
   double mDeltaToa;    // Delta Time of arrival of last sensor input.

   double mTiltX;       // Tilt angle X axis, radians.
   double mTiltY;       // Tilt angle Y axis, radians.

   //***********************************************************************
   // Constructor

   SampleRecord();
};

//***************************************************************************
//***************************************************************************
//***************************************************************************
//QCalls:

// This is a qcall that is called when a new sensor sample record is
// available.
typedef Ris::Threads::QCall1<SampleRecord*> SampleQCall;

// This is a qcall that is called when a sensor session state changes
typedef Ris::Threads::QCall2<int,bool> SessionChangeQCall;

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// special debug.

void specialTest1(char* aLabel,double aX);
void specialTest2(char* aLabel,double aX);

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace

