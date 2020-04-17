#ifndef EVTLNUGAMMA_HH
#define EVTLNUGAMMA_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: B+ -> l+ nu gamma.  Form factor is tree level, from
//  Korchemsky, Pirjol, and Yan,Phy Rev D 61 (200) 114510

class EvtLNuGamma : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;
    void initProbMax() override;
    double getFormFactor( double photonEnergy );

    bool _fafvzero = false;
};

#endif
