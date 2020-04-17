#include "EvtGenBase/EvtPropBreitWignerRel.hh"

#include "EvtGenBase/EvtPatches.hh"

#include <math.h>

EvtPropBreitWignerRel::EvtPropBreitWignerRel( double m0, double g0 ) :
    EvtPropagator( m0, g0 )
{
}

EvtAmplitude<EvtPoint1D>* EvtPropBreitWignerRel::clone() const
{
    return new EvtPropBreitWignerRel( *this );
}

EvtComplex EvtPropBreitWignerRel::amplitude( const EvtPoint1D& x ) const
{
    double m = x.value();
    return 1. / ( _m0 * _m0 - m * m - EvtComplex( 0., _m0 * _g0 ) );
}
