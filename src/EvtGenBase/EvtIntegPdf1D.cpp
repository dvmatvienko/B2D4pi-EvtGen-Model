#include "EvtGenBase/EvtIntegPdf1D.hh"

#include "EvtGenBase/EvtMacros.hh"
#include "EvtGenBase/EvtPatches.hh"

#include <assert.h>

EvtIntegPdf1D::EvtIntegPdf1D( double min, double max ) :
    EvtPdf<EvtPoint1D>(), _min( min ), _max( max )
{
    assert( min <= max );
}

EvtIntegPdf1D::EvtIntegPdf1D( const EvtIntegPdf1D& other ) :
    EvtPdf<EvtPoint1D>( other ), _min( other._min ), _max( other._max )
{
}

EvtValError EvtIntegPdf1D::compute_integral() const
{
    double x1 = pdfIntegral( _min );
    double x2 = pdfIntegral( _max );
    return EvtValError( x2 - x1, 0. );
}

EvtPoint1D EvtIntegPdf1D::randomPoint()
{
    double itgmin = pdfIntegral( _min );
    double itgmax = pdfIntegral( _max );
    double itgrnd = EvtRandom::Flat( itgmin, itgmax );

    return EvtPoint1D( _min, _max, pdfIntegralInverse( itgrnd ) );
}
