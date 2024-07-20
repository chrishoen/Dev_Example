#pragma once

#include "risCmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class is the program command line executive. It processes user
// command line inputs and executes them. It inherits from the command line
// command executive base class, which provides an interface for executing
// command line commands. It provides an override execute function that is
// called by a console executive when it receives a console command line input.
// The execute function then executes the command.

class CmdLineExec : public Ris::BaseCmdLineExec
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constructor.

   CmdLineExec();
   void reset() override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Base class override. Execute a command line command. It calls one of
   // the following specific command execution functions.
   void execute(Ris::CmdLineCmd* aCmd) override;

   // Base class override. Execute special command line command.
   // A special command is one that consists of only a single digit
   // "0" .. "9" followed by an enter.
   void special(int aSpecial) override;

   // Base class override. Show help.
   void executeHelp(Ris::CmdLineCmd* aCmd) override;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Execute specific commands.
   void executeSend      (Ris::CmdLineCmd* aCmd);
   void executeEcho      (Ris::CmdLineCmd* aCmd);
   void executeData      (Ris::CmdLineCmd* aCmd);
   void executeGo1       (Ris::CmdLineCmd* aCmd);
   void executeGo2       (Ris::CmdLineCmd* aCmd);
   void executeGo3       (Ris::CmdLineCmd* aCmd);
   void executeGo4       (Ris::CmdLineCmd* aCmd);
   void executeParms     (Ris::CmdLineCmd* aCmd);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************

