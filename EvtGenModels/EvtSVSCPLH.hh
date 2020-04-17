#ifndef EVTSVSCPLH_HH
#define EVTSVSCPLH_HH

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: The decay of a scalar to a scalar and a vector particle are
//              performed with CP violation and different widths for
//              the cp even and odd states. E.g. B->J/psi K_S.

class EvtSVSCPLH : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtComplex _Af, _Abarf;
    EvtComplex _qop, _poq;

    double _dm;
    double _dgamma;
};

#endif
