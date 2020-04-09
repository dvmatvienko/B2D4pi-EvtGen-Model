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
// Module: EvtGenModels/EvtBToPlnuBK.cc
//
// Description: B->Xu l nu with BK (Becirevic-Kaidalov) parametrization
//              Xu is a pseudoscalar (pi_plus,pi0,eta or eta_prime)
//
// Modification history:
//
//    Martin Simard, U. de Montreal, 08/01/2007    Module created
//
//------------------------------------------------------------------------
//
#include "EvtGenModels/EvtBToPlnuBK.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"

#include "EvtGenModels/EvtBToPlnuBKFF.hh"

#include <assert.h>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::fstream;

std::string EvtBToPlnuBK::getName()
{
    return "BTOPLNUBK";
}

EvtBToPlnuBK* EvtBToPlnuBK::clone()
{
    return new EvtBToPlnuBK;
}

void EvtBToPlnuBK::initProbMax()
{
    EvtId parnum, mesnum, lnum, nunum;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    lnum = getDaug( 1 );
    nunum = getDaug( 2 );

    double mymaxprob = calcamp->CalcMaxProb( parnum, mesnum, lnum, nunum,
                                             BKmodel.get() );

    setProbMax( mymaxprob );
}

void EvtBToPlnuBK::init()
{
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino
    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    EvtSpinType::spintype d1type = EvtPDL::getSpinType( getDaug( 0 ) );
    if ( d1type == EvtSpinType::SCALAR ) {
        checkNArg( 2 );
        BKmodel = std::make_unique<EvtBToPlnuBKFF>( getArg( 0 ), getArg( 1 ) );
        calcamp = std::make_unique<EvtSemiLeptonicScalarAmp>();
    } else {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "BK model handles only scalar meson daughters. Sorry." << endl;
        ::abort();
    }
}

void EvtBToPlnuBK::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    calcamp->CalcAmp( p, _amp2, BKmodel.get() );
}
