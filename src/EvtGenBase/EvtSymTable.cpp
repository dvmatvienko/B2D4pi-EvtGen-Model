#include "EvtGenBase/EvtSymTable.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using std::endl;
using std::fstream;

std::map<std::string, std::string> EvtSymTable::_symMap;

EvtSymTable::EvtSymTable()
{
}

void EvtSymTable::define( const std::string& symname, std::string d )
{
    if ( _symMap.find( symname ) != _symMap.end() ) {
        EvtGenReport( EVTGEN_INFO, "EvtGen" )
            << "Symbol:" << symname.c_str()
            << " redefined, old value:" << _symMap[symname].c_str()
            << " new value:" << d.c_str() << endl;
        _symMap[symname] = d;
        return;
    }

    _symMap[symname] = d;
    return;
}

std::string EvtSymTable::get( const std::string& symname, int& ierr )
{
    ierr = 0;

    if ( _symMap.find( symname ) != _symMap.end() )
        return _symMap[symname];

    // If no matching symbol found just return the string

    return symname;
}
