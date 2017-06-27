/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include <math.h>
#include "my_functions.h"
#include "prnPrint.h"

#include "dspHistoryStatistics.h"

#include "defExampleDefs.h"

namespace Def
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

SensorStatus::SensorStatus()
{
   mHConnectionFlag = false;
   mAConnectionFlag = false;
   mBConnectionFlag = false;

   mAllConnectedFlag = false;
   mAllConnectedChangeFlag = false;
   mLastAllConnectedFlag = false;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Put a sensor session change event.

void SensorStatus::putSessionChange(int aSensorId, bool aConnectionFlag)
{
   // Store the connection flag.
   switch (aSensorId)
   {
   case Def::cSensorH : mHConnectionFlag = aConnectionFlag; break;
   case Def::cSensorA : mAConnectionFlag = aConnectionFlag; break;
   case Def::cSensorB : mBConnectionFlag = aConnectionFlag; break;
   }

   // And them all together.
   mAllConnectedFlag = 
     (mHConnectionFlag &&
      mAConnectionFlag &&
      mBConnectionFlag); 

   // Update logic variables.
   mAllConnectedChangeFlag = mAllConnectedFlag != mLastAllConnectedFlag;
   mLastAllConnectedFlag = mAllConnectedFlag;
}


//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

SampleRecord::SampleRecord()
{
   mSensorId = 0;
   mSeqNum = 0;
   mToa = 0.0;
   mDeltaToa = 0.0;
   mTiltX = 0.0;
   mTiltY = 0.0;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

char* asStringSensor(int aX)
{
   switch (aX)
   {
   case cNone      : return "None";
   case cSensorH   : return "SensorH";
   case cSensorA   : return "SensorA";
   case cSensorB   : return "SensorB";
   default : return "UNKNOWN";
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Special debug.

void specialTest1(char* aLabel, double aX)
{
   if (isfinite(aX) == 0) { printf("ERROR ERROR ERROR ERROR ERROR Test1 %s\n",aLabel); return; }
}

void specialTest2(char* aLabel, double aX)
{
   if (isfinite(aX) == 0) { printf("ERROR ERROR ERROR ERROR ERROR Test2 %s\n",aLabel); return; }
   if (fabs(aX) > 1.0   ) { printf("ERROR ERROR ERROR ERROR ERROR Test2 %s %10.9f\n",aLabel,aX); return; }
}
}//namespace
