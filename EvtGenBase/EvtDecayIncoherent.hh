#ifndef EvtDecayIncoherent_HH
#define EvtDecayIncoherent_HH

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtParticle.hh"

// Description: Base class for models that calculate
//              decay kinematics and do not do any accept/reject.
//              Useful e.g. for interface to other generators

class EvtDecayIncoherent : public EvtDecayBase {
  public:
    void makeDecay( EvtParticle* p, bool recursive = true ) override;

    virtual ~EvtDecayIncoherent() {}

    void setDaughterSpinDensity( int daughter )
    {
        spinDensitySet[daughter] = 1;
        return;
    }

    int isDaughterSpinDensitySet( int daughter )
    {
        return spinDensitySet[daughter];
    }

  private:
    int spinDensitySet[MAX_DAUG];
};

#endif
