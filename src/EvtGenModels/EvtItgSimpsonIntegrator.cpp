#include "EvtGenModels/EvtItgSimpsonIntegrator.hh"

#include "EvtGenBase/EvtPatches.hh"

//-------------
// C Headers --
//-------------
extern "C" {
}

//---------------
// C++ Headers --
//---------------

#include <math.h>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------

#include "EvtGenBase/EvtReport.hh"

#include "EvtGenModels/EvtItgAbsFunction.hh"
using std::endl;

EvtItgSimpsonIntegrator::EvtItgSimpsonIntegrator(
    const EvtItgAbsFunction& theFunction, double precision, int maxLoop ) :
    EvtItgAbsIntegrator( theFunction ),
    _precision( precision ),
    _maxLoop( maxLoop )
{
}

double EvtItgSimpsonIntegrator::evaluateIt( double lower, double higher ) const
{
    // EvtGenReport(EVTGEN_INFO,"EvtGen")<<"in evaluate"<<endl;
    int j;
    double result( 0.0 );
    double s, st, ost( 0.0 );
    for ( j = 1; j < 4; j++ ) {
        st = trapezoid( lower, higher, j, result );
        s = ( 4.0 * st - ost ) / 3.0;
        ost = st;
    }

    double olds( s );
    st = trapezoid( lower, higher, j, result );
    s = ( 4.0 * st - ost ) / 3.0;

    if ( fabs( s - olds ) < _precision * fabs( olds ) ||
         ( s == 0.0 && olds == 0.0 ) )
        return s;

    ost = st;

    for ( j = 5; j < _maxLoop; j++ ) {
        st = trapezoid( lower, higher, j, result );
        s = ( 4.0 * st - ost ) / 3.0;

        if ( fabs( s - olds ) < _precision * fabs( olds ) ||
             ( s == 0.0 && olds == 0.0 ) )
            return s;
        olds = s;
        ost = st;
    }

    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Severe error in EvtItgSimpsonIntegrator.  Failed to converge after loop with 2**"
        << _maxLoop << " calls to the integrand in." << endl;

    return 0.0;
}
