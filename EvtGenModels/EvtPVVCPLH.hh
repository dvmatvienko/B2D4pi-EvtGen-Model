#ifndef EVTPVVCPLH_HH
#define EVTPVVCPLH_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtPVVCPLH : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    bool isBsMixed( EvtParticle* p );
};

#endif
