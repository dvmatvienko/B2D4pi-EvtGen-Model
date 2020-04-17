#ifndef EVT_PROP_BREIT_WIGNER_HH
#define EVT_PROP_BREIT_WIGNER_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtPropagator.hh"

// Non-relativistic Breit-Wigner propagator

class EvtPropBreitWigner : public EvtPropagator {
  public:
    EvtPropBreitWigner( double m0, double g0 );

    EvtAmplitude<EvtPoint1D>* clone() const override;

  protected:
    EvtComplex amplitude( const EvtPoint1D& m ) const override;
};

#endif
