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
// Module: EvtGen/EvtTSS.hh
//
// Description:
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTTSS_HH
#define EVTTSS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

//Class to handle decays of the form TENSOR -> SCALAR SCALAR.
//Calls EvtTensorToScalarScalar

class EvtParticle;

class EvtTSS:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void init() override;
  void decay(EvtParticle *p) override;
  void initProbMax() override;

};

#endif
