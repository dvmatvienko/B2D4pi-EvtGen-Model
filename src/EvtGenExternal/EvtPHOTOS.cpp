#include "EvtGenExternal/EvtPHOTOS.hh"

#include "EvtGenBase/EvtPatches.hh"

#include "EvtGenExternal/EvtExternalGenFactory.hh"

void EvtPHOTOS::doRadCorr( EvtParticle* p )
{
    if ( !_photosEngine ) {
        _photosEngine = EvtExternalGenFactory::getInstance()->getGenerator(
            EvtExternalGenFactory::PhotosGenId );
    }

    if ( _photosEngine ) {
        _photosEngine->doDecay( p );
    }
}
