#ifndef EVTSPINTYPE_HH
#define EVTSPINTYPE_HH

#include "EvtGenBase/EvtReport.hh"

class EvtSpinType {
  public:
    enum spintype
    {
        SCALAR,
        VECTOR,
        TENSOR,
        DIRAC,
        PHOTON,
        NEUTRINO,
        STRING,
        RARITASCHWINGER,
        SPIN3,
        SPIN4,
        SPIN5HALF,
        SPIN7HALF
    };

    static int getSpin2( spintype stype );

    static int getSpinStates( spintype stype );

  private:
};

#endif
