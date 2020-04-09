//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGen/EvtCBTo3piP00.hh
//
// Description:
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTCBTO3PIP00_HH
#define EVTCBTO3PIP00_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBTo3hCP.hh"

class EvtParticle;

class EvtCBTo3piP00 : public EvtDecayAmp {
  public:
    EvtCBTo3piP00() {}

    std::string getName() override;
    EvtCBTo3piP00* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    EvtBTo3hCP generator;
};

#endif
