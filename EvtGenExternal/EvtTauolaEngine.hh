#ifdef EVTGEN_TAUOLA
//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package. If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2011      University of Warwick, UK
//
// Module: EvtTauolaEngine
//
// Description: Interface to the TAUOLA external generator
//
// Modification history:
//
//    John Back       May 2011            Module created
//
//------------------------------------------------------------------------

#ifndef EVTTAUOLAENGINE_HH
#define EVTTAUOLAENGINE_HH

#include "EvtGenModels/EvtAbsExternalGen.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtVector4R.hh"

#ifdef EVTGEN_HEPMC3
#include "Tauola/TauolaHepMC3Particle.h"
#include "Tauola/TauolaHepMC3Event.h"
#include "HepMC3/Units.h"
#include "HepMC3/Relatives.h"
#else
#include "Tauola/TauolaHepMCEvent.h"
#include "Tauola/TauolaHepMCParticle.h"
#include "Tauola/TauolaParticle.h"
#endif
#include "EvtGenBase/EvtHepMCEvent.hh"


#include <vector>
#include <map>

class EvtTauolaEngine : public EvtAbsExternalGen {

public:

  EvtTauolaEngine(bool useEvtGenRandom = true);
  virtual ~EvtTauolaEngine();

  virtual bool doDecay(EvtParticle* theMother);

  virtual void initialise();

protected:

private:

  bool _initialised;
  int _tauPDG, _nTauolaModes;    
  int _neutPropType, _posPropType, _negPropType;

  GenParticlePtr createGenParticle(EvtParticle* theParticle);

  void setUpPossibleTauModes();
  void setOtherParameters();

  int getModeInt(EvtDecayBase* decayModel);

  void decayTauEvent(EvtParticle* tauParticle);

};

#endif

#endif
