#ifdef EVTGEN_TAUOLA

#ifndef EVTTAUOLAENGINE_HH
#define EVTTAUOLAENGINE_HH

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtAbsExternalGen.hh"

#ifdef EVTGEN_HEPMC3
#include "HepMC3/Relatives.h"
#include "HepMC3/Units.h"

#include "Tauola/TauolaHepMC3Event.h"
#include "Tauola/TauolaHepMC3Particle.h"
#else
#include "Tauola/TauolaHepMCEvent.h"
#include "Tauola/TauolaHepMCParticle.h"
#include "Tauola/TauolaParticle.h"
#endif
#include "EvtGenBase/EvtHepMCEvent.hh"

#include <map>
#include <vector>

// Description: Interface to the TAUOLA external generator

class EvtTauolaEngine : public EvtAbsExternalGen {
  public:
    EvtTauolaEngine( bool useEvtGenRandom = true );

    bool doDecay( EvtParticle* theMother ) override;

    void initialise() override;

  protected:
  private:
    bool _initialised;
    int _tauPDG, _nTauolaModes;
    int _neutPropType, _posPropType, _negPropType;

    GenParticlePtr createGenParticle( EvtParticle* theParticle );

    void setUpPossibleTauModes();
    void setOtherParameters();

    int getModeInt( EvtDecayBase* decayModel );

    void decayTauEvent( EvtParticle* tauParticle );
};

#endif

#endif
