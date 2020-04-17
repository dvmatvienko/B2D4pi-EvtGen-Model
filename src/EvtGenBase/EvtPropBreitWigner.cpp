#include "EvtGenBase/EvtPropBreitWigner.hh"

#include "EvtGenBase/EvtConst.hh"
#include "EvtGenBase/EvtPatches.hh"

#include <math.h>

EvtPropBreitWigner::EvtPropBreitWigner( double m0, double g0 ) :
    EvtPropagator( m0, g0 )
{
}

EvtAmplitude<EvtPoint1D>* EvtPropBreitWigner::clone() const
{
    return new EvtPropBreitWigner( *this );
}

EvtComplex EvtPropBreitWigner::amplitude( const EvtPoint1D& x ) const
{
    double m = x.value();
    EvtComplex value = sqrt( _g0 / EvtConst::twoPi ) /
                       ( m - _m0 - EvtComplex( 0.0, _g0 / 2. ) );
    return value;
}
