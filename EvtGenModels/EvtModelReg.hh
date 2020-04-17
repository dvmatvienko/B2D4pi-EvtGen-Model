#ifndef EVTMODELREG_HH
#define EVTMODELREG_HH

#include <list>

class EvtDecayBase;

class EvtModelReg {
  public:
    EvtModelReg( const std::list<EvtDecayBase*>* extraModels = 0 );

  private:
};

#endif
