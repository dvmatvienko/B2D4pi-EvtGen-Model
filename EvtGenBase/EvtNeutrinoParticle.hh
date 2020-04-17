#ifndef EVTNEUTRINOPARTICLE_HH
#define EVTNEUTRINOPARTICLE_HH

#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtParticle.hh"
class EvtId;
class EvtVector4R;

class EvtNeutrinoParticle : public EvtParticle {
  public:
    EvtNeutrinoParticle() = default;
    void init( EvtId part_n, const EvtVector4R& p4 ) override;
    EvtDiracSpinor spParentNeutrino() const override;
    EvtDiracSpinor spNeutrino() const override;
    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtDiracSpinor spinor_rest;
    EvtDiracSpinor spinor_parent;

    EvtNeutrinoParticle( const EvtNeutrinoParticle& n );
    EvtNeutrinoParticle& operator=( const EvtNeutrinoParticle& n );
};
#endif
