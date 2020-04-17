#ifndef EVTBHADRONIC_HH
#define EVTBHADRONIC_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtBHadronic : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBHadronic* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
