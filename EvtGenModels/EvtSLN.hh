#ifndef EVTSLN_HH
#define EVTSLN_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

//Class to handle decays of the type SCALAR -> DIRAC NEUTRINO

class EvtSLN : public EvtDecayAmp {
  public:
    EvtSLN() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;
};

#endif
