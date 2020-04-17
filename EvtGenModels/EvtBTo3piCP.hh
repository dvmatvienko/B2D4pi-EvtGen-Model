#ifndef EVTBTO3PICP_HH
#define EVTBTO3PICP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBTo3hCP.hh"

class EvtParticle;

class EvtBTo3piCP : public EvtDecayAmp {
  public:
    EvtBTo3piCP() {}

    std::string getName() override;
    EvtBTo3piCP* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtBTo3hCP generator;
};

#endif
