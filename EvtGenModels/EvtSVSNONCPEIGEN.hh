#ifndef EVTSVSNONCPEIGEN_HH
#define EVTSVSNONCPEIGEN_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtSVSNONCPEIGEN : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtComplex _A_f;
    EvtComplex _Abar_f;

    EvtComplex _A_fbar;
    EvtComplex _Abar_fbar;

    double _dm;
    double _phickm;
};

#endif
