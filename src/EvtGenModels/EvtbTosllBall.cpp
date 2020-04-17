#include "EvtGenModels/EvtbTosllBall.hh"

#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include "EvtGenModels/EvtbTosllAmp.hh"
#include "EvtGenModels/EvtbTosllBallFF.hh"
#include "EvtGenModels/EvtbTosllScalarAmp.hh"
#include "EvtGenModels/EvtbTosllVectorAmp.hh"

#include <stdlib.h>
#include <string>
using std::endl;

std::string EvtbTosllBall::getName()
{
    return "BTOSLLBALL";
}

EvtDecayBase* EvtbTosllBall::clone()
{
    return new EvtbTosllBall;
}

void EvtbTosllBall::decay( EvtParticle* p )
{
    setWeight( p->initializePhaseSpace( getNDaug(), getDaugs(), false,
                                        _poleSize, 1, 2 ) );

    _calcamp->CalcAmp( p, _amp2, _ballffmodel.get() );
}

void EvtbTosllBall::initProbMax()
{
    EvtId parnum, mesnum, l1num, l2num;

    parnum = getParentId();
    mesnum = getDaug( 0 );
    l1num = getDaug( 1 );
    l2num = getDaug( 2 );

    //This routine sets the _poleSize.
    double mymaxprob = _calcamp->CalcMaxProb( parnum, mesnum, l1num, l2num,
                                              _ballffmodel.get(), _poleSize );

    setProbMax( mymaxprob );
}

void EvtbTosllBall::init()
{
    // First choose form factors from the .DEC file
    // 1 = Ali-Ball '01 LCSR
    // 2 = Ali-Ball '99 LCSR
    // 3 = Colangelo 3pt QCD
    // 4 = Melikhov Lattice/Quark dispersion
    // 5 = ???
    // 6 = Ball-Zwicky '05 LCSR (mb = 480)
    // 7 = Ball-Zwicky '05 LCSR (mb = 460 - pseudoscalar modes only)

    // The default is Ali '01
    int theFormFactorModel = 1;

    if ( getNArg() == 1 )
        theFormFactorModel = (int)getArg( 0 );

    checkNDaug( 3 );

    //We expect the parent to be a scalar
    //and the daughters to be X lepton+ lepton-

    checkSpinParent( EvtSpinType::SCALAR );

    EvtSpinType::spintype mesontype = EvtPDL::getSpinType( getDaug( 0 ) );

    if ( !( mesontype == EvtSpinType::VECTOR ||
            mesontype == EvtSpinType::SCALAR ) ) {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "EvtbTosllBall generator expected "
            << " a SCALAR or VECTOR 1st daughter, found:"
            << EvtPDL::name( getDaug( 0 ) ).c_str() << endl;
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "Will terminate execution!" << endl;
        ::abort();
    }

    checkSpinDaughter( 1, EvtSpinType::DIRAC );
    checkSpinDaughter( 2, EvtSpinType::DIRAC );

    _ballffmodel = std::make_unique<EvtbTosllBallFF>( theFormFactorModel );
    if ( mesontype == EvtSpinType::SCALAR ) {
        _calcamp = std::make_unique<EvtbTosllScalarAmp>();
    } else if ( mesontype == EvtSpinType::VECTOR ) {
        _calcamp = std::make_unique<EvtbTosllVectorAmp>();
    }
}
