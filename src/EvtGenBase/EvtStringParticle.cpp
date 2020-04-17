#include "EvtGenBase/EvtStringParticle.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include <iostream>
#include <math.h>
#include <stdlib.h>

void EvtStringParticle::init( EvtId id, const EvtVector4R& p4 )
{
    _validP4 = true;
    setp( p4 );
    setpart_num( id );
}

void EvtStringParticle::initPartons( int npartons, EvtVector4R* p4partons,
                                     EvtId* idpartons )
{
    _p4partons.resize( npartons );
    _idpartons.resize( npartons );
    for ( int i = 0; i < npartons; i++ ) {
        _p4partons[i] = p4partons[i];
        _idpartons[i] = idpartons[i];
    }
}

int EvtStringParticle::getNPartons()
{
    return _p4partons.size();
}

EvtId EvtStringParticle::getIdParton( int i )
{
    return _idpartons[i];
}

EvtVector4R EvtStringParticle::getP4Parton( int i )
{
    return _p4partons[i];
}

EvtSpinDensity EvtStringParticle::rotateToHelicityBasis() const
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "rotateToHelicityBasis not implemented for strin particle.";
    EvtGenReport( EVTGEN_ERROR, "EvtGen" ) << "Will terminate execution.";

    ::abort();

    EvtSpinDensity rho;
    return rho;
}

EvtSpinDensity EvtStringParticle::rotateToHelicityBasis( double, double,
                                                         double ) const
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "rotateToHelicityBasis(alpha,beta,gamma) not implemented for string particle.";
    EvtGenReport( EVTGEN_ERROR, "EvtGen" ) << "Will terminate execution.";

    ::abort();

    EvtSpinDensity rho;
    return rho;
}
