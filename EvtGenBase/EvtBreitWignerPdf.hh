#ifndef EVT_BREIT_WIGNER_PDF_HH
#define EVT_BREIT_WIGNER_PDF_HH

#include "EvtGenBase/EvtIntegPdf1D.hh"

// Breit-Wigner PDF

class EvtBreitWignerPdf : public EvtIntegPdf1D {
  public:
    EvtBreitWignerPdf( double min, double max, double m0, double g0 );
    EvtBreitWignerPdf( const EvtBreitWignerPdf& other );

    double pdf( const EvtPoint1D& x ) const override;
    EvtPdf<EvtPoint1D>* clone() const override
    {
        return new EvtBreitWignerPdf( *this );
    }

    double pdfIntegral( double m ) const override;
    double pdfIntegralInverse( double x ) const override;

    // accessors

    inline double m0() const { return _m0; }
    inline double g0() const { return _g0; }

  private:
    double _m0;
    double _g0;
};

#endif
