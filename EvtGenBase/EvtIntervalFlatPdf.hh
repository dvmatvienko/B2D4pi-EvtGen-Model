#ifndef EVT_INTERVAL_FLAT_PDF_HH
#define EVT_INTERVAL_FLAT_PDF_HH

#include "EvtGenBase/EvtPdf.hh"
#include "EvtGenBase/EvtPoint1D.hh"

#include <assert.h>

/*
 * Uniform PDF defined on a 1D interval.
 */

class EvtIntervalFlatPdf : public EvtPdf<EvtPoint1D> {
  public:
    EvtIntervalFlatPdf( double min, double max );
    EvtIntervalFlatPdf( const EvtIntervalFlatPdf& other );
    EvtPdf<EvtPoint1D>* clone() const override;

    using EvtPdf<EvtPoint1D>::compute_integral;
    EvtValError compute_integral() const override;
    EvtPoint1D randomPoint() override;

  protected:
    double pdf( const EvtPoint1D& ) const override;

    double _min;
    double _max;
};

#endif
