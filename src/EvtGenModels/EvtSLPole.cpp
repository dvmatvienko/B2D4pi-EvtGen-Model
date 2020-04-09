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
#include "EvtGenModels/EvtSLPole.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicTensorAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtSLPoleFF.hh"

#include <stdlib.h>
#include <string>

std::string EvtSLPole::getName()
{
    return "SLPOLE";
}

EvtDecayBase* EvtSLPole::clone()
{
    return new EvtSLPole;
}

void EvtSLPole::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs(), _resetDaughterTree );
    calcamp->CalcAmp( p, _amp2, SLPoleffmodel.get() );
}

void EvtSLPole::initProbMax()
{
    EvtId parnum, mesnum, lnum, nunum;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    lnum = getDaug( 1 );
    nunum = getDaug( 2 );

    double mymaxprob = calcamp->CalcMaxProb( parnum, mesnum, lnum, nunum,
                                             SLPoleffmodel.get() );

    setProbMax( mymaxprob );
}

void EvtSLPole::init()
{
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    checkSpinParent( EvtSpinType::SCALAR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    EvtSpinType::spintype mesontype = EvtPDL::getSpinType( getDaug( 0 ) );

    SLPoleffmodel = std::make_unique<EvtSLPoleFF>( getNArg(), getArgs() );

    switch ( mesontype ) {
        case EvtSpinType::SCALAR:
            calcamp = std::make_unique<EvtSemiLeptonicScalarAmp>();
            break;
        case EvtSpinType::VECTOR:
            calcamp = std::make_unique<EvtSemiLeptonicVectorAmp>();
            break;
        case EvtSpinType::TENSOR:
            calcamp = std::make_unique<EvtSemiLeptonicTensorAmp>();
            break;
        default:;
    }

    _resetDaughterTree = false;
    if ( getArgStr( getNArg() - 1 ) == "true" )
        _resetDaughterTree = true;
}
