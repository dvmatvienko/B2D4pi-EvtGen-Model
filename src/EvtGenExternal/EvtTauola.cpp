#include "EvtGenExternal/EvtTauola.hh"

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"

#include "EvtGenModels/EvtAbsExternalGen.hh"

#include "EvtGenExternal/EvtExternalGenFactory.hh"

#include <cmath>
#include <iostream>
#include <string>

std::string EvtTauola::getName()
{
    return "TAUOLA";
}

EvtDecayBase* EvtTauola::clone()
{
    return new EvtTauola();
}

void EvtTauola::init()
{
}

void EvtTauola::initProbMax()
{
    noProbMax();
}

void EvtTauola::decay( EvtParticle* p )
{
    // We check to see if the Tauola engine has been created before doing the decay.
    // This should only create the full Tauola engine once, and all clones will
    // point to the same engine.

    if ( !_tauolaEngine ) {
        _tauolaEngine = EvtExternalGenFactory::getInstance()->getGenerator(
            EvtExternalGenFactory::TauolaGenId );
    }

    if ( _tauolaEngine ) {
        _tauolaEngine->doDecay( p );
    }
}
