#ifndef EVTPARTICLEFACTORY_HH
#define EVTPARTICLEFACTORY_HH

#include "EvtGenBase/EvtSpinType.hh"

class EvtParticle;
class EvtId;
class EvtVector4R;
class EvtSpinDensity;

class EvtParticleFactory {
  public:
    static EvtParticle* particleFactory( EvtSpinType::spintype spinType );

    static EvtParticle* particleFactory( EvtId id, EvtVector4R p4 );

    static EvtParticle* particleFactory( EvtId id, EvtVector4R p4,
                                         EvtSpinDensity rho );
};

#endif
