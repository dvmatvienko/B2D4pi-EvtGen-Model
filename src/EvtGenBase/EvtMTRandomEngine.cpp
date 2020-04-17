#include "EvtGenBase/EvtMTRandomEngine.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include <iostream>

EvtMTRandomEngine::EvtMTRandomEngine( unsigned int seed ) :
    engine_( seed ), distribution_( URDist( 0.0, 1.0 ) )
{
    EvtGenReport( EVTGEN_INFO, "EvtMTRandomEngine" )
        << "Mersenne-Twister random number generator with seed = " << seed
        << std::endl;
}

double EvtMTRandomEngine::random()
{
    return distribution_( engine_ );
}
