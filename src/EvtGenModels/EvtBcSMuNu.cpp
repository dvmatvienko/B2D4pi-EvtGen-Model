#include "EvtGenModels/EvtBcSMuNu.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"

#include "EvtGenModels/EvtBCSFF.hh"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

std::string EvtBcSMuNu::getName()
{
    return "BC_SMN";
}

EvtDecayBase* EvtBcSMuNu::clone()
{
    return new EvtBcSMuNu;
}

void EvtBcSMuNu::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    calcamp->CalcAmp( p, _amp2, ffmodel.get() );
}

void EvtBcSMuNu::init()
{
    checkNArg( 1 );
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 0, EvtSpinType::SCALAR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    idScalar = getDaug( 0 ).getId();
    whichfit = int( getArg( 0 ) + 0.1 );

    ffmodel = std::make_unique<EvtBCSFF>( idScalar, whichfit );

    calcamp = std::make_unique<EvtSemiLeptonicScalarAmp>();
}

void EvtBcSMuNu::initProbMax()
{
    EvtId parId = getParentId();
    EvtId mesonId = getDaug( 0 );
    EvtId lepId = getDaug( 1 );
    EvtId nuId = getDaug( 2 );

    int nQ2Bins = 200;
    double maxProb = calcamp->CalcMaxProb( parId, mesonId, lepId, nuId,
                                           ffmodel.get(), nQ2Bins );

    if ( verbose() ) {
        EvtGenReport( EVTGEN_INFO, "EvtBcSMuNu" )
            << "Max prob = " << maxProb << endl;
    }

    setProbMax( maxProb );
}
