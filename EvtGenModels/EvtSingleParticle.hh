#ifndef EVTSINGLEPARTICLE_HH
#define EVTSINGLEPARTICLE_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"
class EvtParticle;

// Description:
//This is a special decay model to generate single particles.

class EvtSingleParticle : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;

    void init() override;

  private:
    double pmin, pmax;
    double cthetamin, cthetamax;
    double phimin, phimax;
};

#endif
