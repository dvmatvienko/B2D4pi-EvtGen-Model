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
// Module: EvtSLPole.cc
//
// Description: Routine to implement semileptonic decays according
//              to light cone sum rules
//
// Modification history:
//
//    DJL       April 23, 1998       Module created
//
//------------------------------------------------------------------------
//
#include "EvtGenModels/EvtKKLambdaC.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicBaryonAmp.hh"

#include "EvtGenModels/EvtKKLambdaCFF.hh"

#include <stdlib.h>
#include <string>

std::string EvtKKLambdaC::getName()
{
    return "KK_LAMBDAC_SL";
}

EvtDecayBase* EvtKKLambdaC::clone()
{
    return new EvtKKLambdaC;
}

void EvtKKLambdaC::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    _calcamp->CalcAmp( p, _amp2, _ffmodel.get() );
}

void EvtKKLambdaC::initProbMax()
{
    EvtId parnum, mesnum, lnum, nunum;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    lnum = getDaug( 1 );
    nunum = getDaug( 2 );

    //double mymaxprob = _calcamp->CalcMaxProb(parnum,mesnum,
    //                           lnum,nunum,_ffmodel);
    double mymaxprob = 100.;
    setProbMax( mymaxprob );
}

void EvtKKLambdaC::init()
{
    checkNDaug( 3 );

    //We expect the parent to be a dirac
    //and the daughters to be dirac lepton neutrino

    checkSpinParent( EvtSpinType::DIRAC );
    checkSpinDaughter( 0, EvtSpinType::DIRAC );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    _ffmodel = std::make_unique<EvtKKLambdaCFF>( getNArg(), getArgs() );

    _calcamp = std::make_unique<EvtSemiLeptonicBaryonAmp>();
}
