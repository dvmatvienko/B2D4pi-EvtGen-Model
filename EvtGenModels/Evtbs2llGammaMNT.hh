#ifndef EVTBS2LLGAMMAMNT_HH
#define EVTBS2LLGAMMAMNT_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;
class Evtbs2llGammaFF;    // my class with ff for rare semileptonic B-decays
class Evtbs2llGammaAmp;    // my class with amplitudes for rare semileptonic B-decays
class EvtbTosllWilsCoeffNLO;    // my class with Wilson coefficients in NLO

// Description: the B -> Gamma ell^+ ell^- decay channel description
//		based on the papers:
//		D.Melikhov, N.Nikitin, K.Toms, Yad. Fiz. 62, No 11
//              and
//              I.Balakireva, D.Melikhov, N.Nikitin, D.Tlisov,
//                                           e-Print: arXiv:0911.0605 [hep-ph].

class Evtbs2llGammaMNT : public EvtDecayAmp {
  public:
    Evtbs2llGammaMNT() {}
    virtual ~Evtbs2llGammaMNT();

    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;
    void decay( EvtParticle* p ) override;

  private:
    Evtbs2llGammaFF* _mntffmodel;
    Evtbs2llGammaAmp* _calcamp;
    EvtbTosllWilsCoeffNLO* _wilscoeff;
};

#endif
