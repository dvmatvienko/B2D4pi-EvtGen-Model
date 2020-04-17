#include "EvtGenModels/EvtItgFunction.hh"

#include "EvtGenBase/EvtPatches.hh"

//-------------
// C Headers --
//-------------
extern "C" {
}

//----------------
// Constructors --
//----------------
EvtItgFunction::EvtItgFunction( double ( *theFunction )( double ),
                                double lowerRange, double upperRange ) :
    EvtItgAbsFunction( lowerRange, upperRange ), _myFunction( theFunction )
{
}

double EvtItgFunction::myFunction( double x ) const
{
    return _myFunction( x );
}
