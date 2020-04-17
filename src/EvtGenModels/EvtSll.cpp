#include "EvtGenModels/EvtSll.hh"

#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4C.hh"

#include <iostream>
#include <stdlib.h>
#include <string>

std::string EvtSll::getName()
{
    return "SLL";
}

EvtDecayBase* EvtSll::clone()
{
    return new EvtSll;
}

void EvtSll::init()
{
    // check that there are 0 arguments
    checkNArg( 0 );
    checkNDaug( 2 );

    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 0, EvtSpinType::DIRAC );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
}

void EvtSll::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    EvtParticle *l1, *l2;
    l1 = p->getDaug( 0 );
    l2 = p->getDaug( 1 );
    EvtVector4R p4_p;
    p4_p.set( p->mass(), 0.0, 0.0, 0.0 );

    EvtVector4C l11, l12, l21, l22;

    l11 = EvtLeptonVACurrent( l1->spParent( 0 ), l2->spParent( 0 ) );
    l12 = EvtLeptonVACurrent( l1->spParent( 0 ), l2->spParent( 1 ) );
    l21 = EvtLeptonVACurrent( l1->spParent( 1 ), l2->spParent( 0 ) );
    l22 = EvtLeptonVACurrent( l1->spParent( 1 ), l2->spParent( 1 ) );

    vertex( 0, 0, p4_p * l11 );
    vertex( 0, 1, p4_p * l12 );
    vertex( 1, 0, p4_p * l21 );
    vertex( 1, 1, p4_p * l22 );

    return;
}
