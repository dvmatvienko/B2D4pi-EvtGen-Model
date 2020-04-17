#ifndef EVTBTOPLNUBK_HH
#define EVTBTOPLNUBK_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:   B->Xu l nu with BK (Becirevic-Kaidalov) parametrization
//                Xu is a pseudoscalar (pi_plus,pi0,eta or eta_prime)

class EvtBToPlnuBK : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBToPlnuBK* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> BKmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> calcamp;
};

#endif
