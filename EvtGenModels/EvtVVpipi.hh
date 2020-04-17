#ifndef EVTVVPIPI_HH
#define EVTVVPIPI_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: For decays of a vector to a vector and 2 pions,
//              the decay is assumed to be dominated by S-wave.

class EvtVVpipi : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
};

#endif
