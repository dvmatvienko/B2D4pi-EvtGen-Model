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
// Module: EvtGen/EvtXPsiGamma.hh
//
// Description:Implementation of the X3872(2-+) -> J/psi gamma decay
//
// Modification history:
//
//    7 May 2012: Module created
//
//------------------------------------------------------------------------

#ifndef EVTXPSIGAMMA_HH
#define EVTXPSIGAMMA_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtId.hh"

#include <fstream>
#include <stdio.h>

class EvtComplex;
class EvtParticle;
class EvtTensor4C;
class EvtVector4C;
class EvtVector4R;

class EvtXPsiGamma : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtDecayBase* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;

  private:
    //  int whichfit;
    EvtComplex fT2( EvtVector4R p, EvtVector4R q, EvtTensor4C epsPI,
                    EvtVector4C epsEps, EvtVector4C epsEta );
    EvtComplex fT3( EvtVector4R p, EvtVector4R q, EvtTensor4C epsPI,
                    EvtVector4C epsEps, EvtVector4C epsEta );
    EvtId _ID0;
    int ncall;
};

#endif
