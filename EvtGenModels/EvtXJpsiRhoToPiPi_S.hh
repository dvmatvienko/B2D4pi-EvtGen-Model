#ifndef EVTXJPSIRHOTOPIPI_S_HH
#define EVTXJPSIRHOTOPIPI_S_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: For decays of X(3872) to J/psi and a intermediate rho0,
//              the decay is assumed to be dominated by S-wave.

class EvtXJpsiRhoToPiPi_S : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
    double BW2_rho0( double );
};

#endif