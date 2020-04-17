#ifndef EVT_DALITZ_FLAT_PDF_HH
#define EVT_DALITZ_FLAT_PDF_HH

#include "EvtGenBase/EvtDalitzPlot.hh"
#include "EvtGenBase/EvtDalitzPoint.hh"
#include "EvtGenBase/EvtPdf.hh"

#include <assert.h>

/*
 * Uniform PDF defined on a Dalitz plot.
 */

class EvtDalitzFlatPdf : public EvtPdf<EvtDalitzPoint> {
  public:
    EvtDalitzFlatPdf( const EvtDalitzPlot& dp );
    EvtDalitzFlatPdf( const EvtDalitzFlatPdf& other );
    EvtPdf<EvtDalitzPoint>* clone() const override;

    using EvtPdf<EvtDalitzPoint>::compute_integral;
    EvtValError compute_integral( int N ) const override;
    EvtDalitzPoint randomPoint() override;

  protected:
    double pdf( const EvtDalitzPoint& ) const override;

    EvtDalitzPlot _dp;
};

#endif
