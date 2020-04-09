
#ifndef EVTPHIDALITZ_HH
#define EVTPHIDALITZ_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtPhiDalitz : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    double _mRho;
    double _gRho;
    double _aD;
    double _phiD;
    double _aOmega;
    double _phiOmega;
    int _locPip;
    int _locPim;
    int _locPi0;
};

#endif
