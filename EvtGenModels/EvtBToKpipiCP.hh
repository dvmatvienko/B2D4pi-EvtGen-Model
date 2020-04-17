#ifndef EVTBTOKPIPICP_HH
#define EVTBTOKPIPICP_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBTo3hCP.hh"

class EvtParticle;

// Description: Routine to decay B->K pi pi
//              and has CP violation.
//       --- This is the routine to be called by the Main generator
//          to get the decay of B0    -->-- K+ pi- pi0
//          The decay proceeeds through three channels:
//          a) B0 -->-- K*+ pi-  ; K*+    -->-- K+ pi0
//          b)          K*0 pi0  ; K*0bar -->-- K+ pi-
//          c)          K-  rho+ ; rho+   -->-- pi+ pi0
//         It provides at the same time the CP conjugate decay
//                              B0bar -->-- K- pi+ pi0

class EvtBToKpipiCP : public EvtDecayAmp {
  public:
    EvtBToKpipiCP() {}

    std::string getName() override;
    EvtBToKpipiCP* clone() override;

    void init() override;
    void decay( EvtParticle* p ) override;

  private:
    EvtBTo3hCP generator;
};

#endif
