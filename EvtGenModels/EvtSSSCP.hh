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
// Module: EvtGen/EvtSSSCP.hh
//
// Description:
//
// Modification history:
//
//    DJL/RYD     August 11, 1998         Module created
//
//------------------------------------------------------------------------

#ifndef EVTSSSCP_HH
#define EVTSSSCP_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;


class EvtSSSCP:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void init() override;
  void initProbMax() override;

  void decay(EvtParticle *p) override;

  std::string getParamName(int i) override;
  std::string getParamDefault(int i) override;

};

#endif
