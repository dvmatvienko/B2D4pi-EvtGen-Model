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
