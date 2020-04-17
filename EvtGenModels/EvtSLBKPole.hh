#ifndef EVTSLBKPOLE_HH    //modified
#define EVTSLBKPOLE_HH    //modified

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"    //modified

#include <memory>
class Evtparticle;

// Description:Semileptonic decays with pole form form factors,
//             according to Becirevic and Kaidalov(BK)

class EvtSLBKPole : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> SLBKPoleffmodel;    //modified
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif
