#include "EvtGenModels/EvtBcVMuNu.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtBCVFF.hh"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

std::string EvtBcVMuNu::getName()
{
    return "BC_VMN";
}

EvtDecayBase* EvtBcVMuNu::clone()
{
    return new EvtBcVMuNu;
}

void EvtBcVMuNu::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    calcamp->CalcAmp( p, _amp2, ffmodel.get() );
}

void EvtBcVMuNu::init()
{
    checkNArg( 1 );
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    checkSpinParent( EvtSpinType::SCALAR );

    checkSpinDaughter( 0, EvtSpinType::VECTOR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    idVector = getDaug( 0 ).getId();
    whichfit = int( getArg( 0 ) + 0.1 );

    ffmodel = std::make_unique<EvtBCVFF>( idVector, whichfit );

    calcamp = std::make_unique<EvtSemiLeptonicVectorAmp>();
}

void EvtBcVMuNu::initProbMax()
{
    EvtId parId = getParentId();
    EvtId mesonId = getDaug( 0 );
    EvtId lepId = getDaug( 1 );
    EvtId nuId = getDaug( 2 );

    int nQ2Bins = 200;
    double maxProb = calcamp->CalcMaxProb( parId, mesonId, lepId, nuId,
                                           ffmodel.get(), nQ2Bins );

    if ( verbose() ) {
        EvtGenReport( EVTGEN_INFO, "EvtBcVMuNu" )
            << "Max prob = " << maxProb << endl;
    }

    setProbMax( maxProb );
}
