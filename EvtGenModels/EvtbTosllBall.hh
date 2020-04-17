#ifndef EVTBTOSLLBALL_HH
#define EVTBTOSLLBALL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <memory>

class EvtbTosllFF;
class EvtbTosllAmp;
class EvtParticle;

// Description:Implementation of the b->sll decays according to Ball et al.

class EvtbTosllBall : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;

  private:
    std::unique_ptr<EvtbTosllAmp> _calcamp;
    std::unique_ptr<EvtbTosllFF> _ballffmodel;
    double _poleSize;
};

#endif
