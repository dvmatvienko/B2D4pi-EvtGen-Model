#ifndef EVTSVPHELAMP_HH
#define EVTSVPHELAMP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

// Description: Routine to decay scalar -> vector + photon
//              by specifying the helicity amplitudes
//
//Class to handle decays of the form SCALAR -> VECTOR PHOTON
//where the helicity amplitudes must be specified. The
//first and third arguments are the magnitudes of the H+
//and H- helicity amplitudes respectively. The second and
//fourth arguements are the phases.
//Calls EvtSVPHel.

class EvtParticle;
class EvtAmp;
class EvtId;

class EvtSVPHelAmp : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

    static void SVPHel( EvtParticle* parent, EvtAmp& amp, EvtId n_v1,
                        EvtId n_ph, const EvtComplex& hp, const EvtComplex& hm );
};

#endif
