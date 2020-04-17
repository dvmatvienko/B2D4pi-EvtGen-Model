#include "EvtGenModels/EvtPhspFlatLifetime.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtRandom.hh"
#include "EvtGenBase/EvtReport.hh"

#include <stdlib.h>
#include <string>

//==============================================================================
// Return the name of the model
//==============================================================================
std::string EvtPhspFlatLifetime::getName()
{
    return "PHSPFLATLIFETIME";
}

//==============================================================================
// Copy the model
//==============================================================================
EvtDecayBase* EvtPhspFlatLifetime::clone()
{
    return new EvtPhspFlatLifetime;
}

//==============================================================================
// Initialize the model
//==============================================================================
void EvtPhspFlatLifetime::init()
{
    // check that there is 1 argument in the decay file
    checkNArg( 1 );
    // this argument is the lifetime upper edge (in ps)
    m_maxLifetime = getArg( 0 );
}

//==============================================================================
// Compute the maximum probability (max of the pdf)
//==============================================================================
void EvtPhspFlatLifetime::initProbMax()
{
    noProbMax();
}

//==============================================================================
// Decay the particle according to the model
//==============================================================================
void EvtPhspFlatLifetime::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );
    // generate the lifetime flat between 0 and max
    double l = EvtRandom::Flat( 0., m_maxLifetime );
    // modify the lifetime of the particle (in mm)
    p->setLifetime( l * EvtConst::c * 1.e-12 );
}
