#ifndef EVTDMIX_HH
#define EVTDMIX_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

class EvtDMix : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    double _rd;
    double _xpr;
    double _ypr;
};

#endif
