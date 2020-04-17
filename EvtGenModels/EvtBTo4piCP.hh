#ifndef EVTBTO4PICP_HH
#define EVTBTO4PICP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtBTo4piCP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBTo4piCP* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
