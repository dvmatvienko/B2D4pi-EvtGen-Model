#ifndef EVTHELAMP_HH
#define EVTHELAMP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtId.hh"

#include <memory>

class EvtParticle;
class EvtEvalHelAmp;

// Description:Decay model for implementation of generic 2 body
//             decay specified by the helicity amplitudes

class EvtHelAmp : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    void fillHelicity( int* lambda2, int n, int J2, EvtId id );

    std::unique_ptr<EvtEvalHelAmp> _evalHelAmp;
};

#endif
