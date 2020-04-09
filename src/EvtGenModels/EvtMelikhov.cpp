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
// Module: EvtMelikhov.cc
//
// Description: Routine to implement semileptonic B->D*lnu decays according
//              to the model HQET
//
// Modification history:
//
//    DJL     April 20, 1998        Module created
//
//------------------------------------------------------------------------
//
#include "EvtGenModels/EvtMelikhov.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtMelikhovFF.hh"

#include <stdlib.h>
#include <string>

std::string EvtMelikhov::getName()
{
    return "MELIKHOV";
}

EvtDecayBase* EvtMelikhov::clone()
{
    return new EvtMelikhov;
}

void EvtMelikhov::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    calcamp->CalcAmp( p, _amp2, Melikhovffmodel.get() );
}

void EvtMelikhov::init()
{
    checkNArg( 1 );
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 0, EvtSpinType::VECTOR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    Melikhovffmodel = std::make_unique<EvtMelikhovFF>( getArg( 0 ) );
    calcamp = std::make_unique<EvtSemiLeptonicVectorAmp>();
}
