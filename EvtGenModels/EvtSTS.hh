#ifndef EVTSTS_HH
#define EVTSTS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description:Performs the decay of a scalar -> tensor scalar

class EvtSTS : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
