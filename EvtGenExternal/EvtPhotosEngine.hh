#ifdef EVTGEN_PHOTOS
//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package. If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2011      University of Warwick, UK
//
// Module: EvtPhotosEngine
//
// Description: Interface to the PHOTOS external generator
//
// Modification history:
//
//    John Back       May 2011            Module created
//
//------------------------------------------------------------------------

#ifndef EVTPHOTOSENGINE_HH
#define EVTPHOTOSENGINE_HH

#include "EvtGenModels/EvtAbsExternalGen.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtVector4R.hh"


#ifdef EVTGEN_HEPMC3
#include "Photos/PhotosHepMC3Event.h"
#include "Photos/PhotosHepMC3Particle.h"
#include "HepMC3/Units.h"
#else
#include "Photos/PhotosHepMCEvent.h"
#include "Photos/PhotosHepMCParticle.h"
#include "Photos/PhotosParticle.h"
#endif
#include "EvtGenBase/EvtHepMCEvent.hh"

#include <string>

class EvtPhotosEngine : public EvtAbsExternalGen {

public:

  EvtPhotosEngine(std::string photonType = "gamma", bool useEvtGenRandom = true);

  bool doDecay(EvtParticle* theMother) override;

  void initialise() override;

private:

  std::string _photonType;
  EvtId _gammaId;
  int _gammaPDG;
  double _mPhoton;
  bool _initialised;

  GenParticlePtr createGenParticle(EvtParticle* theParticle, bool incoming);
  int getNumberOfPhotons(const GenVertexPtr theVertex) const;

};

#endif

#endif
