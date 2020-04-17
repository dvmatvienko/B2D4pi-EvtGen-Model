#ifdef EVTGEN_PYTHIA

#ifndef EVTPYTHIAENGINE_HH
#define EVTPYTHIAENGINE_HH

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtAbsExternalGen.hh"

#include "EvtGenExternal/EvtPythiaRandom.hh"

#include "Pythia8/ParticleData.h"
#include "Pythia8/Pythia.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

// Description: Interface to the Pytha 8 external generator

class EvtPythiaEngine : public EvtAbsExternalGen {
  public:
    EvtPythiaEngine( std::string xmlDir = "./xmldoc",
                     bool convertPhysCodes = false, bool useEvtGenRandom = true );

    virtual ~EvtPythiaEngine();

    bool doDecay( EvtParticle* theMother ) override;

    void initialise() override;

  protected:
  private:
    void updateParticleLists();
    void updatePhysicsParameters();

    void createPythiaParticle( EvtId& particleId, int PDGCode );
    bool validPDGCode( int PDGCode );
    void updatePythiaDecayTable( EvtId& particleId, int aliasInt, int PDGCode );
    void storeDaughterInfo( EvtParticle* theParticle, int startInt );

    void clearDaughterVectors();
    void clearPythiaModeMap();

    void createDaughterEvtParticles( EvtParticle* theParent );

    int getModeInt( EvtDecayBase* decayModel );

    std::unique_ptr<Pythia8::Pythia> _genericPythiaGen;
    std::unique_ptr<Pythia8::Pythia> _aliasPythiaGen;
    Pythia8::Pythia* _thePythiaGenerator;

    std::vector<int> _daugPDGVector;
    std::vector<EvtVector4R> _daugP4Vector;

    typedef std::map<int, std::vector<int>> PythiaModeMap;
    PythiaModeMap _pythiaModeMap;

    bool _convertPhysCodes, _initialised, _useEvtGenRandom;

    std::unique_ptr<EvtPythiaRandom> _evtgenRandom;

    std::map<int, int> _addedPDGCodes;
};

#endif

#endif
