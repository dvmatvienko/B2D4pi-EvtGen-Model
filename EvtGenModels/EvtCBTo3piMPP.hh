#ifndef EVTCBTO3PIMPP_HH
#define EVTCBTO3PIMPP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBTo3hCP.hh"

class EvtParticle;

class EvtCBTo3piMPP : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtCBTo3piMPP* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtBTo3hCP generator;
};

#endif
