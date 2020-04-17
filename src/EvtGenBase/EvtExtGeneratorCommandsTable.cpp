#include "EvtGenBase/EvtExtGeneratorCommandsTable.hh"

EvtExtGeneratorCommandsTable::EvtExtGeneratorCommandsTable()
{
    _commandMap.clear();
}

EvtExtGeneratorCommandsTable::~EvtExtGeneratorCommandsTable()
{
    _commandMap.clear();
}

EvtExtGeneratorCommandsTable* EvtExtGeneratorCommandsTable::getInstance()
{
    static EvtExtGeneratorCommandsTable* theCommandMap = 0;

    if ( theCommandMap == 0 ) {
        theCommandMap = new EvtExtGeneratorCommandsTable();
    }

    return theCommandMap;
}
