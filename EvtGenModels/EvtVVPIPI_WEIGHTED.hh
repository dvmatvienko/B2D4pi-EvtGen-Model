#ifndef EVTVVPIPI_WEIGHTED_HH
#define EVTVVPIPI_WEIGHTED_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <string>

class EvtParticle;

// Description: For decays of a vector to a vector and 2 pions,
//              the decay is assumed to be dominated by S-wave.

class EvtVVPIPI_WEIGHTED : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
