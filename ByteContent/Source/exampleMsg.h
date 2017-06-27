#pragma once
/*==============================================================================
This file contains a set of classes that encapsulate a message set.

There is a class for each particular message in the set and there is a
base class that all of the messages inherit from.

These messages follow the ByteContent pattern, where they all inherit
from ByteContent so that they can be copied to/from ByteBuffers.

The base class is used to specify set membership, any inheriting class
is a member of the message set, and message objects can be referenced
anonymously via pointers to the the base class.

The base class provides a member function, makeFromByteBuffer, that
extracts particular messages from a byte buffer and returns a pointer
to the base class.

These messages all have the same common form, they all contain a
common message header. The base class has a Header member object that
encapsulates the header.
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include <Windows.h>
#include "risByteContent.h"
#include "risByteMsgMonkey.h"
#include "exampleMsgBase.h"

namespace Example
{
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Message Types

class MsgIdT
{
public:

   static const int   cUnspecifiedMsg    = 0;
   static const int   cTestMsg           = 1;
   static const int   cFirstMessageMsg   = 2;
   static const int   cSampleRecordMsg   = 3;
   static const int   cTimeSyncMsg       = 4;
   static const int   cFileHeaderMsg     = 5;

};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Particular message classes.
// There is one class for each message in the message set.

class TestMsg : public BaseMsg
{
public:

   //***************************************************************************
   // Members:

   int mCode1;
   int mCode2;
   int mCode3;
   int mCode4;

   //***************************************************************************
   // Methods:

   TestMsg();
   void reset();
   void copyToFrom (Ris::ByteBuffer* aBuffer);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

class FirstMessageMsg : public BaseMsg
{
public:

   //***************************************************************************
   // Members:

   int mCode1;

   //***************************************************************************
   // Methods:

   FirstMessageMsg();
   void reset();
   void copyToFrom (Ris::ByteBuffer* aBuffer);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

class SampleRecordMsg : public BaseMsg
{
public:

   //***************************************************************************
   // Members:

   unsigned int mSensorId;      // Identifier.
   unsigned int mSeqNum;        // Sequence nunber.  

   float mToa;                  // Time of arrival of sensor input.
   float mDeltaToa;             // Delta Time of arrival of last sensor input.

   float mTiltX;                // Tilt angle X axis, radians.
   float mTiltY;                // Tilt angle Y axis, radians.

   //***************************************************************************
   // Methods:

   SampleRecordMsg();
   void reset();
   void copyToFrom (Ris::ByteBuffer* aBuffer);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

class TimeSyncMsg : public BaseMsg
{
public:

   //***************************************************************************
   // Members:

   double      mProgramTime;
   SYSTEMTIME  mSystemTime;

   //***************************************************************************
   // Methods:

   TimeSyncMsg();
   void reset();
   void copyToFrom(Ris::ByteBuffer* aBuffer);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

class FileHeaderMsg : public BaseMsg
{
public:

   //***************************************************************************
   // Members:

   int         mHeaderState;
   int         mJointCode;
   int         mSampleCount;

   SYSTEMTIME  mCreateSystemTime;
   SYSTEMTIME  mCloseSystemTime;

   double      mCreateProgramTime;
   double      mCloseProgramTime;

   double      mFirstToa;
   double      mLastToa;
   double      mDurationToa;

   //***************************************************************************
   // Methods:

   FileHeaderMsg();
   void reset();
   void copyToFrom(Ris::ByteBuffer* aBuffer);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
// Message creator:

class MsgCreator : public Ris::BaseMsgCreator
{
public:
   //***********************************************************************
   // Create a new message, based on a message type.

   Ris::ByteContent* createMsg (int aMessageType) override;
};

}//namespace


