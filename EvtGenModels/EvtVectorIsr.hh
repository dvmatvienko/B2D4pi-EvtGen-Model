#ifndef EVTVECTORISR_HH
#define EVTVECTORISR_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

// Description:
//   This is a special decay model to generate e+e- -> phi gamma + soft gammas
//   using soft collinear ISR calculation from AfkQed
//   This is implemented as a decay of the VPHO.

class EvtVectorIsr : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;

    void init() override;

    void initProbMax() override;

    double ckhrad1( double xx, double a, double b );

    void ckhrad( const double& e_beam, const double& q2_min, double& e01,
                 double& e02, double& f );

  private:
    double csfrmn, csbkmn;
    double fmax;
    bool firstorder;
};

#endif
