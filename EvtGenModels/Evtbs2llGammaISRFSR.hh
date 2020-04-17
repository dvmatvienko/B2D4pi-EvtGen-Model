#ifndef EVTBS2LLGAMMAISRFSR_HH
#define EVTBS2LLGAMMAISRFSR_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class Evtbs2llGammaFF;    // my class with ff for rare semileptonic B-decays
class Evtbs2llGammaISRFSRAmp;    // my class with amplitudes for rare radiative leptonic B-decays
class EvtbTosllWilsCoeffNLO;    // my class with Wilson coefficients in NLO

// Description: See the Internal LHCb Note LHCb-INT-2011-011.

class Evtbs2llGammaISRFSR : public EvtDecayAmp {
  public:
    Evtbs2llGammaISRFSR() {}
    virtual ~Evtbs2llGammaISRFSR();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

  private:
    Evtbs2llGammaFF* _mntffmodel;
    Evtbs2llGammaISRFSRAmp* _calcamp;
    EvtbTosllWilsCoeffNLO* _wilscoeff;
};

#endif
