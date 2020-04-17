#ifndef EVTTSS_HH
#define EVTTSS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

//Class to handle decays of the form TENSOR -> SCALAR SCALAR.
//Calls EvtTensorToScalarScalar

class EvtParticle;

class EvtTSS : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;
    void initProbMax() override;
};

#endif
