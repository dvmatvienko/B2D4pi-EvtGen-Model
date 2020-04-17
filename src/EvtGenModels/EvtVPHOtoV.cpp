#include "EvtGenModels/EvtVPHOtoV.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4C.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include <stdlib.h>
#include <string>

std::string EvtVPHOtoV::getName()
{
    return "VPHOTOV";
}

EvtDecayBase* EvtVPHOtoV::clone()
{
    return new EvtVPHOtoV;
}

void EvtVPHOtoV::init()
{
    // check that there are 0 arguments
    checkNArg( 0 );

    // check that there are 1 daughters
    checkNDaug( 1 );

    // check the parent and daughter spins
    checkSpinParent( EvtSpinType::VECTOR );
    checkSpinDaughter( 0, EvtSpinType::VECTOR );
}

void EvtVPHOtoV::initProbMax()
{
    setProbMax( 1.0 );
}

void EvtVPHOtoV::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    EvtParticle* d = p->getDaug( 0 );

    d->setP4( p->getP4Restframe() );

    vertex( 0, 0, p->eps( 0 ) * p->epsParent( 0 ).conj() );
    vertex( 1, 0, p->eps( 1 ) * p->epsParent( 0 ).conj() );
    vertex( 2, 0, p->eps( 2 ) * p->epsParent( 0 ).conj() );

    vertex( 0, 1, p->eps( 0 ) * p->epsParent( 1 ).conj() );
    vertex( 1, 1, p->eps( 1 ) * p->epsParent( 1 ).conj() );
    vertex( 2, 1, p->eps( 2 ) * p->epsParent( 1 ).conj() );

    vertex( 0, 2, p->eps( 0 ) * p->epsParent( 2 ).conj() );
    vertex( 1, 2, p->eps( 1 ) * p->epsParent( 2 ).conj() );
    vertex( 2, 2, p->eps( 2 ) * p->epsParent( 2 ).conj() );

    return;
}
