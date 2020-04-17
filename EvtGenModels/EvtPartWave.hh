#ifndef EVTPARTWAVE_HH
#define EVTPARTWAVE_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtEvalHelAmp.hh"
#include "EvtGenBase/EvtId.hh"

#include <memory>

class EvtParticle;
class EvtEvalHelAmp;

// Description:Decay model for implementation of generic 2 body
//             decay specified by the partial waves amplitudes

class EvtPartWave : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    void fillHelicity( int* lambda2, int n, int J2 );

    std::unique_ptr<EvtEvalHelAmp> _evalHelAmp;
};

#endif
