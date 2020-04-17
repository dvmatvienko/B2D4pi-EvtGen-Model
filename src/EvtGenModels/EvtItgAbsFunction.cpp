#include "EvtGenModels/EvtItgAbsFunction.hh"

#include "EvtGenBase/EvtPatches.hh"

//-------------
// C Headers --
//-------------
extern "C" {
}
#include "EvtGenBase/EvtReport.hh"

#include "assert.h"
using std::endl;

EvtItgAbsFunction::EvtItgAbsFunction( double lowerRange, double upperRange ) :
    _upperRange( upperRange ), _lowerRange( lowerRange )
{
}

double EvtItgAbsFunction::value( double x ) const
{
    if ( x >= _lowerRange && x <= _upperRange )
        return myFunction( x );
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Error in EvtItgAbsFunction::value.  Given co-ordinate " << x
        << " is outside of allowed range [" << _lowerRange << ", "
        << _upperRange << "].  Returning 0.0" << endl;
    return 0.0;    // Never get here
}

double EvtItgAbsFunction::operator()( double x ) const
{
    return myFunction( x );
}
