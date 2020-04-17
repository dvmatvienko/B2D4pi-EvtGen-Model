#ifndef EVTBTOVLNUBALL_HH
#define EVTBTOVLNUBALL_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicFF.hh"

#include <memory>

class EvtParticle;

// Description:   B->Xu l nu with the Ball/Zwicky decay model
//                Xu is a vector (rho, rho0, omega)

class EvtBToVlnuBall : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBToVlnuBall* clone() override;

    void decay( EvtParticle* p ) override;
    void initProbMax() override;
    void init() override;

  private:
    std::unique_ptr<EvtSemiLeptonicFF> _Ballmodel;
    std::unique_ptr<EvtSemiLeptonicAmp> _calcamp;
};
#endif
