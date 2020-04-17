#include "EvtGenBase/EvtRadCorr.hh"

#include "EvtGenBase/EvtAbsRadCorr.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include <iostream>
#include <stdlib.h>
using std::endl;

EvtAbsRadCorr* EvtRadCorr::_fsrEngine = 0;
bool EvtRadCorr::_alwaysRadCorr = false;
bool EvtRadCorr::_neverRadCorr = false;

EvtRadCorr::EvtRadCorr()
{
    _fsrEngine = 0;
    _alwaysRadCorr = false;
    _neverRadCorr = false;
}

EvtRadCorr::~EvtRadCorr()
{
    if ( _fsrEngine )
        delete _fsrEngine;
    _fsrEngine = 0;
}

void EvtRadCorr::setRadCorrEngine( EvtAbsRadCorr* fsrEngine )
{
    _fsrEngine = fsrEngine;
}

void EvtRadCorr::doRadCorr( EvtParticle* p )
{
    if ( _fsrEngine == 0 ) {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "No RadCorr model available in "
            << "EvtRadCorr::doRadCorr()." << endl;
        ::abort();
    }

    if ( !_neverRadCorr )
        _fsrEngine->doRadCorr( p );
    return;
}

bool EvtRadCorr::alwaysRadCorr()
{
    return _alwaysRadCorr;
}
bool EvtRadCorr::neverRadCorr()
{
    return _neverRadCorr;
}

void EvtRadCorr::setAlwaysRadCorr()
{
    _alwaysRadCorr = true;
    _neverRadCorr = false;
}
void EvtRadCorr::setNeverRadCorr()
{
    _alwaysRadCorr = false;
    _neverRadCorr = true;
}
void EvtRadCorr::setNormalRadCorr()
{
    _alwaysRadCorr = false;
    _neverRadCorr = false;
}
