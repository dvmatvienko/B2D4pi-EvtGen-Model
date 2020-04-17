#include "EvtGenModels/EvtISGW.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtSemiLeptonicScalarAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicTensorAmp.hh"
#include "EvtGenBase/EvtSemiLeptonicVectorAmp.hh"

#include "EvtGenModels/EvtISGWFF.hh"

#include <stdlib.h>
#include <string>

std::string EvtISGW::getName()
{
    return "ISGW";
}

EvtDecayBase* EvtISGW::clone()
{
    return new EvtISGW;
}

void EvtISGW::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    calcamp->CalcAmp( p, _amp2, isgwffmodel.get() );
}

void EvtISGW::init()
{
    checkNArg( 0 );
    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton neutrino

    EvtSpinType::spintype mesontype = EvtPDL::getSpinType( getDaug( 0 ) );

    checkSpinParent( EvtSpinType::SCALAR );
    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::NEUTRINO );

    isgwffmodel = std::make_unique<EvtISGWFF>();

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
