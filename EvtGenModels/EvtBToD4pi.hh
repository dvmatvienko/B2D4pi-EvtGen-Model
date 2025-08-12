//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
//
// Module: EvtGen/EvtBToD4pi.hh (D. Matvienko, 08.2022)
//
// Description: This class describes evtgen resonant model for B0 -> D+ (4pi)- decay
//------------------------------------------------------------------------

#ifndef EVTBTOD4PI_HH
#define EVTBTOD4PI_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtBToD4pi : public EvtDecayAmp  {

public:

  EvtBToD4pi() {}
  virtual ~EvtBToD4pi();

  std::string getName() const override;
  EvtBToD4pi* clone() const override;

  void init() override;
  void initProbMax() override;
  void decay(EvtParticle *p) override; 

};

#endif
