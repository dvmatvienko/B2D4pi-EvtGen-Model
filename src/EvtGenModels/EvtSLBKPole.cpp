#include "EvtGenModels/EvtSLBKPole.hh"    //modified

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicTensorAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtSLBKPoleFF.hh"    //modified

#include <stdlib.h>
#include <string>

std::string EvtSLBKPole::getName()
{
    return "SLBKPOLE";    //modified
}

EvtDecayBase* EvtSLBKPole::clone()
{    //modified

    return new EvtSLBKPole;
}

void EvtSLBKPole::decay( EvtParticle* p )
{    //modified

    p->initializePhaseSpace( getNDaug(), getDaugs() );

    calcamp->CalcAmp( p, _amp2, SLBKPoleffmodel.get() );    //modified
    return;
}

void EvtSLBKPole::initProbMax()
{
    EvtId parnum, mesnum, lnum, nunum;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    lnum = getDaug( 1 );
    nunum = getDaug( 2 );

    double mymaxprob = calcamp->CalcMaxProb( parnum, mesnum, lnum, nunum,
                                             SLBKPoleffmodel.get() );    //modified

    setProbMax( mymaxprob );
}

void EvtSLBKPole::init()
{    //modified

    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    checkSpinParent( EvtSpinType::SCALAR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    EvtSpinType::spintype mesontype = EvtPDL::getSpinType( getDaug( 0 ) );

    SLBKPoleffmodel = std::make_unique<EvtSLBKPoleFF>( getNArg(),
                                                       getArgs() );    //modified

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
}
