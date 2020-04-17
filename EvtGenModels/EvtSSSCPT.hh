#ifndef EVTSSSCPT_HH
#define EVTSSSCPT_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSSSCPT : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
};

#endif
