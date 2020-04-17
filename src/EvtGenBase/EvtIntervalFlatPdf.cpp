#include "EvtGenBase/EvtIntervalFlatPdf.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtRandom.hh"

#include <assert.h>

EvtIntervalFlatPdf::EvtIntervalFlatPdf( double min, double max ) :
    EvtPdf<EvtPoint1D>(), _min( min ), _max( max )
{
    assert( max >= min );
}

EvtIntervalFlatPdf::EvtIntervalFlatPdf( const EvtIntervalFlatPdf& other ) :
    EvtPdf<EvtPoint1D>( other ), _min( other._min ), _max( other._max )
{
}

EvtPdf<EvtPoint1D>* EvtIntervalFlatPdf::clone() const
{
    return new EvtIntervalFlatPdf( *this );
}

double EvtIntervalFlatPdf::pdf( const EvtPoint1D& ) const
{
    return 1.;
}

EvtValError EvtIntervalFlatPdf::compute_integral() const
{
    return EvtValError( _max - _min, 0. );
}

EvtPoint1D EvtIntervalFlatPdf::randomPoint()
{
    return EvtPoint1D( _min, _max, EvtRandom::Flat( _min, _max ) );
}
