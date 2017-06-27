/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <stdio.h>
#include <string.h>
#include "exampleMsg.h"


namespace Example
{
//******************************************************************************
//******************************************************************************
//******************************************************************************

TestMsg::TestMsg ()
{
   reset();
} 

void TestMsg::reset ()
{
   mMessageType = MsgIdT::cTestMsg;
   mCode1 = 901;
   mCode2 = 902;
   mCode3 = 903;
   mCode4 = 904;
} 

void TestMsg::copyToFrom (Ris::ByteBuffer* aBuffer)
{
   mHeader.headerCopyToFrom(aBuffer,this);

   aBuffer->copy( &mCode1 );
   aBuffer->copy( &mCode2 );
   aBuffer->copy( &mCode3 );
   aBuffer->copy( &mCode4 );

   mHeader.headerReCopyToFrom(aBuffer,this);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

FirstMessageMsg::FirstMessageMsg ()
{
   reset();
} 

void FirstMessageMsg::reset ()
{
   mMessageType = MsgIdT::cFirstMessageMsg;
   mCode1 = 0;
} 

void FirstMessageMsg::copyToFrom (Ris::ByteBuffer* aBuffer)
{
   mHeader.headerCopyToFrom(aBuffer,this);

   aBuffer->copy( & mCode1 );

   mHeader.headerReCopyToFrom(aBuffer,this);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

SampleRecordMsg::SampleRecordMsg ()
{
   reset();
} 

void SampleRecordMsg::reset ()
{
   mMessageType = MsgIdT::cSampleRecordMsg;

   mSensorId = 0;
   mSeqNum = 0;
   mToa = 0.0;
   mDeltaToa = 0.0;
   mTiltX = 0.0;
   mTiltY = 0.0;
} 

void SampleRecordMsg::copyToFrom (Ris::ByteBuffer* aBuffer)
{
   mHeader.headerCopyToFrom(aBuffer,this);

   aBuffer->copy ( & mSensorId );
   aBuffer->copy ( & mSeqNum   );
   aBuffer->copy ( & mToa      );
   aBuffer->copy ( & mDeltaToa );
   aBuffer->copy ( & mTiltX    );
   aBuffer->copy ( & mTiltY    );

   mHeader.headerReCopyToFrom(aBuffer,this);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

TimeSyncMsg::TimeSyncMsg()
{
   reset();
}

void TimeSyncMsg::reset()
{
   mMessageType = MsgIdT::cTimeSyncMsg;

   mProgramTime = 0.0;
   memset(&mSystemTime,0,sizeof(mSystemTime));
}

void TimeSyncMsg::copyToFrom(Ris::ByteBuffer* aBuffer)
{
   mHeader.headerCopyToFrom(aBuffer, this);

   aBuffer->copy ( & mProgramTime );
   aBuffer->copyBlock ( &    mSystemTime,  sizeof(mSystemTime)  );

   mHeader.headerReCopyToFrom(aBuffer, this);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

FileHeaderMsg::FileHeaderMsg ()
{
   reset();
}

void FileHeaderMsg::reset ()
{
   mMessageType = MsgIdT::cFileHeaderMsg;

   mHeaderState = 0;
   mJointCode = 0;
   mSampleCount = 0;

   memset(&mCreateSystemTime,0,sizeof(mCreateSystemTime));
   memset(&mCloseSystemTime,0,sizeof(mCloseSystemTime));

   mCreateProgramTime = 0.0;
   mCloseProgramTime = 0.0;

   mFirstToa = 0.0;
   mLastToa = 0.0;;
   mDurationToa = 0.0;;
}

void FileHeaderMsg::copyToFrom(Ris::ByteBuffer* aBuffer)
{
   mHeader.headerCopyToFrom(aBuffer, this);

   aBuffer->copy ( &    mHeaderState       );
   aBuffer->copy ( &    mJointCode         );
   aBuffer->copy ( &    mSampleCount       );

   aBuffer->copyBlock ( &    mCreateSystemTime,  sizeof(mCreateSystemTime)  );
   aBuffer->copyBlock ( &    mCloseSystemTime,   sizeof(mCloseSystemTime)   );

   aBuffer->copy ( &    mCreateProgramTime );
   aBuffer->copy ( &    mCloseProgramTime  );

   aBuffer->copy ( &    mFirstToa          );
   aBuffer->copy ( &    mLastToa           );
   aBuffer->copy ( &    mDurationToa       );

   mHeader.headerReCopyToFrom(aBuffer, this);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This creates a new message, based on a message type

Ris::ByteContent* MsgCreator::createMsg (int aMessageType)
{
   Ris::ByteContent* tMsg = 0;

   switch (aMessageType)
   {
   case MsgIdT::cTestMsg :
      tMsg = new TestMsg;
      break;
   case MsgIdT::cFirstMessageMsg :
      tMsg = new FirstMessageMsg;
      break;
   case MsgIdT::cSampleRecordMsg :
      tMsg = new SampleRecordMsg;
      break;
   case MsgIdT::cTimeSyncMsg :
      tMsg = new TimeSyncMsg;
      break;
   case MsgIdT::cFileHeaderMsg :
      tMsg = new FileHeaderMsg;
      break;
   default :
      return 0;
      break;
   }
   return tMsg;
}

}//namespace


