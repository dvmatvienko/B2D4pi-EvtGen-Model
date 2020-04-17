#ifndef EVTBTOXSGAMMA_HH
#define EVTBTOXSGAMMA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include "EvtGenModels/EvtBtoXsgammaAbsModel.hh"

#include <memory>

class EvtParticle;

// Class to generate non-resonant two-body b->s,gamma decays.

class EvtBtoXsgamma : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    std::unique_ptr<EvtBtoXsgammaAbsModel> _model;
};

#endif
