#include "EvtGenModels/EvtBToPlnuBKFF.hh"

#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include <math.h>
#include <stdlib.h>
#include <string>

EvtBToPlnuBKFF::EvtBToPlnuBKFF( double alpha, double beta )
{
    _alpha = alpha;
    _beta = beta;

    return;
}

void EvtBToPlnuBKFF::getscalarff( EvtId parent, EvtId /*daught*/, double t,
                                  double /*mass*/, double* fp, double* f0 )
{
    //Define mBstar
    EvtId Bplus = EvtPDL::getId( "B+" );
    EvtId Bminus = EvtPDL::getId( "B-" );
    double mBstar = EvtPDL::getMeanMass( EvtPDL::getId( "B*0" ) );
    if ( parent == Bplus || parent == Bminus )
        mBstar = EvtPDL::getMeanMass( EvtPDL::getId( "B*+" ) );
    double mBstar2 = mBstar * mBstar;

    //Compute BK parametrization (t==q2)
    double fplus = 1.0 /
                   ( ( 1.0 - t / mBstar2 ) * ( 1.0 - _alpha * t / mBstar2 ) );
    double fzero = 1.0 / ( 1.0 - t / ( mBstar2 * _beta ) );

    *fp = fplus;
    *f0 = fzero;

    return;
}

void EvtBToPlnuBKFF::getvectorff( EvtId, EvtId, double, double, double*,
                                  double*, double*, double* )
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Not implemented :getvectorff in EvtBToPlnuBKFF.\n";
    ::abort();
}

void EvtBToPlnuBKFF::gettensorff( EvtId, EvtId, double, double, double*,
                                  double*, double*, double* )
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Not implemented :gettensorff in EvtBToPlnuBKFf.\n";
    ::abort();
}

void EvtBToPlnuBKFF::getbaryonff( EvtId, EvtId, double, double, double*,
                                  double*, double*, double* )
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Not implemented :getbaryonff in EvtBToPlnuBKFF.\n";
    ::abort();
}

void EvtBToPlnuBKFF::getdiracff( EvtId, EvtId, double, double, double*, double*,
                                 double*, double*, double*, double* )
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Not implemented :getdiracff in EvtBToPlnuBKFF.\n";
    ::abort();
}

void EvtBToPlnuBKFF::getraritaff( EvtId, EvtId, double, double, double*,
                                  double*, double*, double*, double*, double*,
                                  double*, double* )
{
    EvtGenReport( EVTGEN_ERROR, "EvtGen" )
        << "Not implemented :getraritaff in EvtBToPlnuBKFF.\n";
    ::abort();
}
