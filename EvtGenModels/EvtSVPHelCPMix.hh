#ifndef EVTSVPHELCPMIX_HH
#define EVTSVPHELCPMIX_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

// Description: The decay of a scalar Bs meson to a vector particle and a photon is
//              performed with CP violation and different widths for
//              the heavy and light states (DeltaGamma_s =! 0). E.g. Bs->phi gamma.
// Model input arguments:
//   |H+| arg|H+| |H-| arg|H-| beta_s
// H+ and H- don't need to be normalized.
// beta_s in radians.

class EvtSVPHelCPMix : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;

    void decay( EvtParticle* p ) override;
};

#endif
