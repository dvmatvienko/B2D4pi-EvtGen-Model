#include "EvtGenModels/EvtEtaDalitz.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include <stdlib.h>
#include <string>

std::string EvtEtaDalitz::getName()
{
    return "ETA_DALITZ";
}

EvtDecayBase* EvtEtaDalitz::clone()
{
    return new EvtEtaDalitz;
}

void EvtEtaDalitz::init()
{
    // check that there are 0 arguments
    checkNArg( 0 );
    checkNDaug( 3 );

    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 0, EvtSpinType::SCALAR );
    checkSpinDaughter( 1, EvtSpinType::SCALAR );
    checkSpinDaughter( 2, EvtSpinType::SCALAR );
}

void EvtEtaDalitz::initProbMax()
{
    setProbMax( 2.1 );
}

void EvtEtaDalitz::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    EvtVector4R mompi0 = p->getDaug( 2 )->getP4();
    double masspip = p->getDaug( 0 )->mass();
    double masspim = p->getDaug( 1 )->mass();
    double masspi0 = p->getDaug( 2 )->mass();
    double m_eta = p->mass();

    double y;

    //The decay amplitude coems from Layter et al PRD 7 2565 (1973).

    y = ( mompi0.get( 0 ) - masspi0 ) *
            ( 3.0 / ( m_eta - masspip - masspim - masspi0 ) ) -
        1.0;

    EvtComplex amp( sqrt( 1.0 - 1.07 * y ), 0.0 );

    vertex( amp );

    return;
}
