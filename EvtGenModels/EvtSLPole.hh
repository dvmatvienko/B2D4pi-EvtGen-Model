#ifndef EVTSLPOLE_HH
#define EVTSLPOLE_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class Evtparticle;

class EvtSLPole : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> SLPoleffmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
    //special case - reset the daughter masses
    bool _resetDaughterTree;
};

#endif
