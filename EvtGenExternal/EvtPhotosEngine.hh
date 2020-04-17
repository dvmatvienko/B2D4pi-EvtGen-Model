#ifdef EVTGEN_PHOTOS
#ifndef EVTPHOTOSENGINE_HH
#define EVTPHOTOSENGINE_HH

#include "EvtGenBase/EvtHepMCEvent.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtAbsExternalGen.hh"
#ifdef EVTGEN_HEPMC3
#include "HepMC3/Units.h"

#include "Photos/PhotosHepMC3Event.h"
#include "Photos/PhotosHepMC3Particle.h"
#else
#include "Photos/PhotosHepMCEvent.h"
#include "Photos/PhotosHepMCParticle.h"
#include "Photos/PhotosParticle.h"
#endif

#include <string>

// Description: Interface to the PHOTOS external generator

class EvtPhotosEngine : public EvtAbsExternalGen {
  public:
    EvtPhotosEngine( std::string photonType = "gamma",
                     bool useEvtGenRandom = true );

    bool doDecay( EvtParticle* theMother ) override;

    void initialise() override;

  private:
    std::string _photonType;
    EvtId _gammaId;
    int _gammaPDG;
    double _mPhoton;
    bool _initialised;

    GenParticlePtr createGenParticle( EvtParticle* theParticle, bool incoming );
    int getNumberOfPhotons( const GenVertexPtr theVertex ) const;
};

#endif

#endif
