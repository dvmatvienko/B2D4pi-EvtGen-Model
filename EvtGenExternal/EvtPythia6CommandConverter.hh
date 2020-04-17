#ifndef EVTPYTHIA6COMMANDCONVERTER_HH
#define EVTPYTHIA6COMMANDCONVERTER_HH

#include "EvtGenBase/EvtExtGeneratorCommandsTable.hh"

#include <string>
#include <vector>

// Description:  Function to replace Pythia 6 commands with the
//               corresponding Pythia 8 commands.

std::vector<std::string> convertPythia6Command( Command command );

#endif
