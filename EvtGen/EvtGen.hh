#ifndef EVTGEN_HH
#define EVTGEN_HH

#include "EvtGenBase/EvtPDL.hh"

#include <list>

class EvtParticle;
class EvtRandomEngine;
class EvtVector4R;
class EvtStdHep;
class EvtSpinDensity;
class EvtAbsRadCorr;
class EvtDecayBase;
class EvtHepMCEvent;

class EvtGen {
  public:
    EvtGen( const char* const decayName, const char* const pdtTableName,
            EvtRandomEngine* randomEngine = 0, EvtAbsRadCorr* isrEngine = 0,
            const std::list<EvtDecayBase*>* extraModels = 0, int mixingType = 1,
            bool useXml = false );

    ~EvtGen();

    void readUDecay( const char* const udecay_name, bool useXml = false );

    EvtHepMCEvent* generateDecay( int PDGid, EvtVector4R refFrameP4,
                                  EvtVector4R translation,
                                  EvtSpinDensity* spinDensity = 0 );

    void generateDecay( EvtParticle* p );

  private:
    EvtPDL _pdl;
    int _mixingType;
};

#endif
