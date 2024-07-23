#include "stdafx.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "risProgramTime.h"
#include "risBitUtils.h"
#include "my_functions.h"
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
   if(aCmd->isCmd("RESET"))   reset();
   if (aCmd->isCmd("GO1"))    executeGo1(aCmd);
   if (aCmd->isCmd("GO2"))    executeGo2(aCmd);
   if (aCmd->isCmd("GO3"))    executeGo3(aCmd);
   if (aCmd->isCmd("GO4"))    executeGo4(aCmd);
   if (aCmd->isCmd("GO5"))    executeGo5(aCmd);
   if (aCmd->isCmd("GO6"))    executeGo6(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

inline void delay(int aLoop)
{
    int gDummy = 0;
    for (int i = 0; i < aLoop; i++) gDummy++;
}
void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
    aCmd->setArgDefault(1, 0);
    int tDelay = aCmd->argInt(1);

    double tT1 = Ris::getProgramTimeUS();
    delay(tDelay);
    double tDiff = Ris::getProgramTimeUS() - tT1;

    Prn::print(0, "tDiff  %.8f", tDiff);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void my_soft_delay_us(int aDelayUs)
{
    double tT1 = Ris::getProgramTimeUS();
    while (1)
    {
        double tDiff = Ris::getProgramTimeUS() - tT1;
        if (tDiff >= aDelayUs) break;
    }
}

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
    aCmd->setArgDefault(1, 0);
    int tDelay = aCmd->argInt(1);

    double tT1 = Ris::getProgramTimeUS();
    my_soft_delay_us(tDelay);
    double tDiff = Ris::getProgramTimeUS() - tT1;

    Prn::print(0, "tDiff  %.8f", tDiff);

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
   printf("printf\n");
   Prn::print(0, "Prn::print 0");
   Prn::print(Prn::Show1, "Prn::print Prn::Show1");
   Prn::print(Prn::Show2, "Prn::print Prn::Show");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo6(Ris::CmdLineCmd* aCmd)
{
   Prn::print(0, "Ris::portableGetBinDir() %s", Ris::portableGetBinDir());
   Prn::print(0, "Ris::portableGetBinDir() %s", Ris::portableGetBinDir());
   double tTime = Ris::getProgramTime();
   unsigned int tTimeMS = Ris::getCpuTimeUIntMS();

   Prn::print(0, "Ris::getProgramTime           %10.6f", tTime);
   Prn::print(0, "Ris::getCpuTimeUIntMs         %10d", tTimeMS);
}

