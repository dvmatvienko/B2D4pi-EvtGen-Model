#include "EvtGenModels/EvtItgPtrFunction.hh"

#include "EvtGenBase/EvtPatches.hh"

//-------------
// C Headers --
//-------------
extern "C" {
}

//----------------
// Constructors --
//----------------
EvtItgPtrFunction::EvtItgPtrFunction(
    double ( *theFunction )( double, const std::vector<double>& ),
    double lowerRange, double upperRange, const std::vector<double>& coeffs1 ) :
    EvtItgAbsFunction( lowerRange, upperRange ),
    _myFunction( theFunction ),
    _coeffs1( coeffs1 )
{
}

double EvtItgPtrFunction::myFunction( double x ) const
{
    return _myFunction( x, _coeffs1 );
}

void EvtItgPtrFunction::setCoeff( int vect, int which, double value )
{
    if ( vect == 1 )
        _coeffs1[which] = value;
}

double EvtItgPtrFunction::getCoeff( int vect, int which )
{
    if ( vect == 1 )
        return _coeffs1[which];
    else {
        return 0;
    }
}
