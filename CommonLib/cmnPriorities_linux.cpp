/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include "stdafx.h"

#define  _CMNPRIORITIES_CPP_
#include "cmnPriorities.h"

namespace Cmn
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor.

Priorities::Priorities()
{
   mTimer         = Ris::Threads::Priority(-1, 70);
   mQCall         = Ris::Threads::Priority(-1, 70);
   mLong          = Ris::Threads::Priority(-1, 60);
   mShort         = Ris::Threads::Priority(-1, 70);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace
