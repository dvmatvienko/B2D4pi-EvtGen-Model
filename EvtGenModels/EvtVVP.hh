#ifndef EVTVVP_HH
#define EVTVVP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtParticle;
class EvtDecayBase;

// Description: Routine to implement radiative decay
//                   chi_c1 -> psi gamma
//                   chi_c1 -> psi ell ell

class EvtVVP : public EvtDecayAmp {
  public:
    EvtVVP() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;

  private:
    void decay_2body( EvtParticle* p );
    void decay_3body( EvtParticle* p );
    double delta;    // form factor parameter
};

#endif
