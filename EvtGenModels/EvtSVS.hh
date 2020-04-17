#ifndef EVTSVS_HH
#define EVTSVS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
//Class to handle decays of the form SCALAR->VECTOR SCALAR
//Calls EvtScalarToVectorScalar.

class EvtSVS : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;
};

#endif
