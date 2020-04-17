#ifndef EVTSIMPLERANDOMENGINE_HH
#define EVTSIMPLERANDOMENGINE_HH

#include "EvtGenBase/EvtRandomEngine.hh"

class EvtSimpleRandomEngine : public EvtRandomEngine {
  public:
    EvtSimpleRandomEngine() { _next = 1; }

    void reset() { _next = 1; }

    double random() override;

  private:
    unsigned long int _next;
};

#endif
