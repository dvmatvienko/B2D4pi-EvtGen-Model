#ifndef EvtSVP_HH
#define EvtSVP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtParticle;
class EvtDecayBase;

// Description: Routine to implement radiative decay
//                   chi_c0 -> psi gamma
//                   chi_c0 -> psi ell ell

class EvtSVP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;

  private:
    void decay_2body( EvtParticle* p );
    void decay_3body( EvtParticle* p );
    double delta;    // form factor parameter
};

#endif
