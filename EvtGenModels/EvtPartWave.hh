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
// Module: EvtGen/EvtPartWave.hh
//
// Description:Decay model for implementation of generic 2 body
//             decay specified by the partial waves amplitudes
//
// Modification history:
//
//    RYD      September 7, 1999         Module created
//
//------------------------------------------------------------------------

#ifndef EVTPARTWAVE_HH
#define EVTPARTWAVE_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtEvalHelAmp.hh"
#include "EvtGenBase/EvtId.hh"

#include <memory>

class EvtParticle;
class EvtEvalHelAmp;

class EvtPartWave : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void init() override;
    void initProbMax() override;

    void decay( EvtParticle* p ) override;

  private:
    void fillHelicity( int* lambda2, int n, int J2 );

    std::unique_ptr<EvtEvalHelAmp> _evalHelAmp;
};

#endif
