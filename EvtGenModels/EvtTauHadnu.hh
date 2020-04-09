//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998     Caltech, UCSB
//
// Module: EvtGen/EvtTauHadnu.hh
//
// Description:
//
// Modification history:
//
//  Lange Oct 26, 2002 Created
//
//------------------------------------------------------------------------

#ifndef EVTTAUHADNUKS_HH
#define EVTTAUHADNUKS_HH

#include "EvtGenBase/EvtDecayAmp.hh"

class EvtParticle;

class EvtTauHadnu : public EvtDecayAmp {
  public:
    EvtTauHadnu() {}

    std::string getName() override;
    EvtDecayBase* clone() override;

    void initProbMax() override;
    void init() override;
    void decay( EvtParticle* p ) override;

  private:
    double _beta;
    double _mRho;
    double _gammaRho;
    double _mRhopr;
    double _gammaRhopr;
    double _mA1;
    double _gammaA1;

    double gFunc( double m2, int dupD );
    EvtComplex Fpi( double s, double xm1, double xm2 );
    EvtComplex BW( double s, double m, double gamma, double xm1, double xm2 );
};

#endif
