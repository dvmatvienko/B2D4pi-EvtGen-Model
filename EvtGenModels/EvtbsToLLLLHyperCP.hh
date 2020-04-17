#ifndef EVTBSTOLLLL_HYPERCP_HH
#define EVTBSTOLLLL_HYPERCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class EvtbsToLLLLHyperCPAmp;    // my class with amplitudes for rare four-leptonic B-decays

class EvtbsToLLLLHyperCP : public EvtDecayAmp {
  public:
    EvtbsToLLLLHyperCP(){};
    virtual ~EvtbsToLLLLHyperCP();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

  private:
    EvtbsToLLLLHyperCPAmp* _calcamp;
};

#endif
