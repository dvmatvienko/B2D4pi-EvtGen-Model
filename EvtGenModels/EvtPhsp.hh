#ifndef EVTPHSP_HH
#define EVTPHSP_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

// Description:
//Class to handle generic phase space decays not done
//in other decay models.

class EvtPhsp : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
