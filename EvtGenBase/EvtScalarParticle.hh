#ifndef EVTSCALARPARTICLE_HH
#define EVTSCALARPARTICLE_HH

#include "EvtGenBase/EvtParticle.hh"
class EvtId;

class EvtScalarParticle : public EvtParticle {
  public:
    EvtScalarParticle() {}

    void init( EvtId part_n, double e, double px, double py, double pz );
    void init( EvtId part_n, const EvtVector4R& p ) override;

    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtScalarParticle( const EvtScalarParticle& scalar );
    EvtScalarParticle& operator=( const EvtScalarParticle& scalar );
};

#endif
