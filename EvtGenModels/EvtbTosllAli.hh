//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 2003      Caltech
//
// Module: EvtGen/EvtbTosllAli.hh
//
// Description:Implementation of the b->sll decays according to Ali '01 et al.
//
// Modification history:
//
//    Ryd     March 30, 2003         Module created
//
//------------------------------------------------------------------------

#ifndef EVTBTOSLLALI_HH
#define EVTBTOSLLALI_HH


#include "EvtGenBase/EvtDecayAmp.hh"
#include <memory>

class EvtbTosllFF;
#include "EvtGenModels/EvtbTosllAmp.hh"
#include "EvtGenModels/EvtbTosllFF.hh"
class EvtParticle;

class EvtbTosllAli:public  EvtDecayAmp  {

public:

  std::string getName() override;
  EvtDecayBase* clone() override;

  void decay(EvtParticle *p) override;
  void init() override;
  void initProbMax() override;

private:
  std::unique_ptr<EvtbTosllFF> _aliffmodel;
  std::unique_ptr<EvtbTosllAmp> _calcamp;
  double _poleSize;
};

#endif

