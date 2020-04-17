#ifndef EVTCBTO3PIP00_HH
#define EVTCBTO3PIP00_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBTo3hCP.hh"

class EvtParticle;

class EvtCBTo3piP00 : public EvtDecayAmp {
  public:
    EvtCBTo3piP00() {}

    std::string getName() override;
    EvtCBTo3piP00* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtBTo3hCP generator;
};

#endif
