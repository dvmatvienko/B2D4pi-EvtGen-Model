#ifndef EVT_PROP_BREIT_WIGNER_REL_HH
#define EVT_PROP_BREIT_WIGNER_REL_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtPropagator.hh"

// Relativistic Breit-Wigner Propagator

class EvtPropBreitWignerRel : public EvtPropagator {
  public:
    EvtPropBreitWignerRel( double m0, double g0 );

    EvtAmplitude<EvtPoint1D>* clone() const override;

  protected:
    EvtComplex amplitude( const EvtPoint1D& x ) const override;
};

#endif
