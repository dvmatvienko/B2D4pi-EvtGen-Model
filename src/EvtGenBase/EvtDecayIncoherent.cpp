#include "EvtGenBase/EvtDecayIncoherent.hh"

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtRadCorr.hh"
#include "EvtGenBase/EvtReport.hh"

void EvtDecayIncoherent::makeDecay( EvtParticle* p, bool recursive )
{
    //initialize this the hard way..
    //Lange June 26, 2000
    for ( size_t i = 0; i < static_cast<unsigned int>( MAX_DAUG ); i++ ) {
        spinDensitySet[i] = 0;
    }

    _daugsDecayedByParentModel = false;

    decay( p );
    p->setDecayProb( 1.0 );

    EvtSpinDensity rho;

    rho.setDiag( p->getSpinStates() );

    p->setSpinDensityBackward( rho );

    if ( getPHOTOS() || EvtRadCorr::alwaysRadCorr() ) {
        EvtRadCorr::doRadCorr( p );
    }

    if ( !recursive )
        return;

    //Now decay the daughters.

    if ( !daugsDecayedByParentModel() ) {
        for ( size_t i = 0; i < p->getNDaug(); i++ ) {
            //Need to set the spin density of the daughters to be
            //diagonal.
            rho.setDiag( p->getDaug( i )->getSpinStates() );
            //if (p->getDaug(i)->getNDaug()==0){
            //only do this if the user has not already set the
            //spin density matrix herself.
            //Lange June 26, 2000
            if ( isDaughterSpinDensitySet( i ) == 0 ) {
                p->getDaug( i )->setSpinDensityForward( rho );
            } else {
                //EvtGenReport(EVTGEN_INFO,"EvtGen") << "spinDensitymatrix already set!!!\n";
                EvtSpinDensity temp = p->getDaug( i )->getSpinDensityForward();
                //	EvtGenReport(EVTGEN_INFO,"EvtGen") <<temp<<endl;
            }
            //Now decay the daughter.  Really!
            p->getDaug( i )->decay();
        }
    }
}
