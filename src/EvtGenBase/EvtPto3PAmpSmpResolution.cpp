#include "EvtGenBase/EvtPto3PAmpSmpResolution.hh"

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtCyclic3.hh"
#include "EvtGenBase/EvtDalitzCoord.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtPto3PAmp.hh"

#include <assert.h>
#include <iostream>
#include <math.h>
using EvtCyclic3::Index;
using EvtCyclic3::Pair;
using std::cout;
using std::endl;

EvtPto3PAmpSmpResolution::EvtPto3PAmpSmpResolution( EvtDalitzPlot dp,
                                                    Pair pairAng, Pair pairRes,
                                                    EvtSpinType::spintype spin,
                                                    const EvtPropagator& prop,
                                                    NumType typeN ) :
    EvtPto3PAmp( dp, pairAng, pairRes, spin, prop, typeN )
{
}

EvtComplex EvtPto3PAmpSmpResolution::evalPropagator( double m ) const
{
    EvtComplex prop( 0, 0 );

    if ( _sigma > 0 ) {    // convolved
        int nconv = 20;
        double min = m + _bias - _sigma * 2.5;
        double max = m + _bias + _sigma * 2.5;
        double dm = ( max - min ) / nconv;
        static double sqrt2pi = sqrt( 2 * 3.14159 );
        double ifact = 1. / ( sqrt2pi * _sigma );
        for ( int i = 0; i < nconv; i++ ) {
            double mprime = min + dm * ( i + 0.5 );
            double t = ( mprime - m ) / _sigma;
            prop += ifact * exp( -0.5 * t * t ) *
                    EvtPto3PAmp::evalPropagator( m ) * dm;
        }
    } else {
        prop = EvtPto3PAmp::evalPropagator( m );
    }

    return prop;
}
