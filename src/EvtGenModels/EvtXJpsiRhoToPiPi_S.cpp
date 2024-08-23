#include "EvtGenModels/EvtXJpsiRhoToPiPi_S.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtTensor4C.hh"
#include "EvtGenBase/EvtVector4C.hh"

#include <stdlib.h>
#include <string>
using std::endl;

std::string EvtXJpsiRhoToPiPi_S::getName()
{
    return "XJPSIRHO0PIPI_S";
}

EvtDecayBase* EvtXJpsiRhoToPiPi_S::clone()
{
    return new EvtXJpsiRhoToPiPi_S;
}

void EvtXJpsiRhoToPiPi_S::init(){
    static EvtId PIP = EvtPDL::getId( "pi+" );
    static EvtId PIM = EvtPDL::getId( "pi-" );

    // check that there are 0 arguments
    checkNArg( 0 );
    checkNDaug( 3 );

    checkSpinParent( EvtSpinType::VECTOR );
    checkSpinDaughter( 0, EvtSpinType::VECTOR );

    if ( ( !( getDaug( 1 ) == PIP && getDaug( 2 ) == PIM ) ) ) {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "EvtXJpsiRhoToPiPi_S generator expected "
            << " pi+ and pi- "
            << "as 2nd and 3rd daughter. " << endl;
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "Will terminate execution!" << endl;
        ::abort();
    }
}

void EvtXJpsiRhoToPiPi_S::initProbMax()
{
    //Hard coded... should not be hard to calculate...
    setProbMax( 10.0 );
}

double EvtXJpsiRhoToPiPi_S::BW2_rho0( double mPiPi )
{
    double mRho0 = 0.7755;
    double tauRho0 = 0.1462;
    double BWrho2 = (mPiPi * tauRho0) / ((mRho0 * mRho0 - mPiPi * mPiPi) * (mRho0 * mRho0 - mPiPi * mPiPi) + mRho0 * tauRho0 * mRho0 * tauRho0);
    return BWrho2;
}

void EvtXJpsiRhoToPiPi_S::decay( EvtParticle* p )
{
    p->initializePhaseSpace( getNDaug(), getDaugs() );

    EvtParticle *v, *s1, *s2;

    v = p->getDaug( 0 );
    s1 = p->getDaug( 1 );
    s2 = p->getDaug( 2 );

    //  Put phase space results into the daughters.

    EvtVector4C ep0, ep1, ep2;

    ep0 = p->eps( 0 );
    ep1 = p->eps( 1 );
    ep2 = p->eps( 2 );

    // Jpsi momentum in the X rest frame
    EvtVector4R k =
        p->getDaug( 0 )->getP4();    // J-psi momentum in X rest frame

    double kstar = sqrt(k.get( 1 ) * k.get( 1) + k.get( 2 ) * k.get( 2) + k.get( 3 ) * k.get( 3 ));

    // we are using S-wave approximation
    double f0X = 1.0;
    double mPiPi = (s1->getP4() + s2->getP4()).mass();
    double fac = kstar * f0X * BW2_rho0( mPiPi );

    vertex( 0, 0, fac * ( ep0 * v->epsParent( 0 ).conj() ) );
    vertex( 0, 1, fac * ( ep0 * v->epsParent( 1 ).conj() ) );
    vertex( 0, 2, fac * ( ep0 * v->epsParent( 2 ).conj() ) );

    vertex( 1, 0, fac * ( ep1 * v->epsParent( 0 ).conj() ) );
    vertex( 1, 1, fac * ( ep1 * v->epsParent( 1 ).conj() ) );
    vertex( 1, 2, fac * ( ep1 * v->epsParent( 2 ).conj() ) );

    vertex( 2, 0, fac * ( ep2 * v->epsParent( 0 ).conj() ) );
    vertex( 2, 1, fac * ( ep2 * v->epsParent( 1 ).conj() ) );
    vertex( 2, 2, fac * ( ep2 * v->epsParent( 2 ).conj() ) );

    return;
}