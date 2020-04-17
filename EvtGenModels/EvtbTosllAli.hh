#ifndef EVTBTOSLLALI_HH
#define EVTBTOSLLALI_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <memory>

class EvtbTosllFF;
#include "EvtGenModels/EvtbTosllAmp.hh"
#include "EvtGenModels/EvtbTosllFF.hh"
class EvtParticle;

// Description:Implementation of the b->sll decays according to Ali '01 et al.

class EvtbTosllAli : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;

  private:
    std::unique_ptr<EvtbTosllFF> _aliffmodel;
    std::unique_ptr<EvtbTosllAmp> _calcamp;
    double _poleSize;
};

#endif
