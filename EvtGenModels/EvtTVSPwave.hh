#ifndef EVTTVSPWAVE_HH
#define EVTTVSPWAVE_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

//Class to handles decays of the form TENSOR -> VECTOR SCALAR,
//which proceed via S,P, or D partial waves.  There are
//six arguements, which are the magnetude and phase of
//each partial wave (S, P then D).  Calls EvtTensorToVectorScalar

class EvtTVSPwave : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;

    std::string getParamName( int i ) override;
    std::string getParamDefault( int i ) override;
};

#endif
