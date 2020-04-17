#ifndef EvtTVP_HH
#define EvtTVP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtDecayBase;
class EvtParticle;

// Description: Routine to implement radiative decay
//                   chi_c2 -> psi gamma
//                   chi_c2 -> psi ell ell
//		matrix element from [S.P Baranov et al, PRD 85, 014034 (2012)]

class EvtTVP : public EvtDecayAmp {
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
