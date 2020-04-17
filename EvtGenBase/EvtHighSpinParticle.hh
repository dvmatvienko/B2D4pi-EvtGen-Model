#ifndef EVTHIGHSPINPARTICLE_HH
#define EVTHIGHSPINPARTICLE_HH

#include "EvtGenBase/EvtParticle.hh"

class EvtId;

class EvtHighSpinParticle : public EvtParticle {
  public:
    EvtHighSpinParticle() = default;

    void init( EvtId id, const EvtVector4R& p ) override;

    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;
};

#endif
