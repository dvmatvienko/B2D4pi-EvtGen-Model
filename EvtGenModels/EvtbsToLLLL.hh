#ifndef EVTBSTOLLLL_HH
#define EVTBSTOLLLL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class Evtbs2llGammaFF;    // my class with ff for rare semileptonic B-decays
class EvtbsToLLLLAmp;    // my class with amplitudes for rare four-leptonic B-decays
class EvtbTosllWilsCoeffNLO;    // my class with Wilson coefficients in NLO

class EvtbsToLLLL : public EvtDecayAmp {
  public:
    EvtbsToLLLL(){};
    virtual ~EvtbsToLLLL();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

  private:
    Evtbs2llGammaFF* _mntffmodel;
    EvtbsToLLLLAmp* _calcamp;
    EvtbTosllWilsCoeffNLO* _wilscoeff;
};

#endif
