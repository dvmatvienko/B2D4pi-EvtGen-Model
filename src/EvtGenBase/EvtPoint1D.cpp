#include "EvtGenBase/EvtPoint1D.hh"

#include "EvtGenBase/EvtPatches.hh"

#include <stdio.h>

EvtPoint1D::EvtPoint1D() :
    _min( 0. ), _max( -1. ), _value( 0. ), _valid( false )
{
}

EvtPoint1D::EvtPoint1D( double value ) :
    _min( 0. ), _max( -1. ), _value( value ), _valid( true )
{
}

EvtPoint1D::EvtPoint1D( double min, double max, double value ) :
    _min( min ),
    _max( max ),
    _value( value ),
    _valid( ( _min <= _value && _value <= _max ) ? true : false )
{
}

void EvtPoint1D::print() const
{
    printf( "%f (%f : %f)\n", _value, _min, _max );
}
