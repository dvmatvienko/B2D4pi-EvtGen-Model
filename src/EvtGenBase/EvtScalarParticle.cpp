#include "EvtGenBase/EvtScalarParticle.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include <iostream>
#include <math.h>

void EvtScalarParticle::init( EvtId part_n, double e, double px, double py,
                              double pz )
{
    _validP4 = true;
    setp( e, px, py, pz );
    setpart_num( part_n );

    setLifetime();
}

void EvtScalarParticle::init( EvtId part_n, const EvtVector4R& p4 )
{
    _validP4 = true;
    setp( p4 );
    setpart_num( part_n );

    setLifetime();
}

EvtSpinDensity EvtScalarParticle::rotateToHelicityBasis() const
{
    EvtSpinDensity R;
    R.setDim( 1 );

    R.set( 0, 0, 1.0 );

    return R;
}

EvtSpinDensity EvtScalarParticle::rotateToHelicityBasis( double, double,
                                                         double ) const
{
    EvtSpinDensity R;
    R.setDim( 1 );

    R.set( 0, 0, 1.0 );

    return R;
}
