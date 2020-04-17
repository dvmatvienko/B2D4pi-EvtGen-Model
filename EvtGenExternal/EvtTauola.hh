#ifndef EVTTAUOLA_HH
#define EVTTAUOLA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;
class EvtAbsExternalGen;
class EvtDecayBase;

// Description: Use the Tauola external generator for tau decays

class EvtTauola : public EvtDecayIncoherent {
  public:
    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  protected:
    EvtAbsExternalGen* _tauolaEngine = nullptr;

  private:
};

#endif
