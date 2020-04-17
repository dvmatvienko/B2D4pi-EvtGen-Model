#ifndef EVT_INTEG_PDF_1D_HH
#define EVT_INTEG_PDF_1D_HH

#include "EvtGenBase/EvtPdf.hh"
#include "EvtGenBase/EvtPoint1D.hh"

// Analytically integrable one dimensional PDF.

class EvtIntegPdf1D : public EvtPdf<EvtPoint1D> {
  public:
    EvtIntegPdf1D( double min, double max );
    EvtIntegPdf1D( const EvtIntegPdf1D& );

    // Pdf integral function and its inverse to be defined in subclasses

    virtual double pdfIntegral( double x ) const = 0;
    virtual double pdfIntegralInverse( double x ) const = 0;

    using EvtPdf<EvtPoint1D>::compute_integral;
    EvtValError compute_integral() const override;
    EvtPoint1D randomPoint() override;

  protected:
    double _min;
    double _max;
};

#endif
