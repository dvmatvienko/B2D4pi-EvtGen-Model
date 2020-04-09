//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Module: EvtBtoXsgammaKagan.cc
//
// Description:
//       Routine to perform two-body B->Xs,gamma decays with a fixed hadronic
//       mass. For spectrum measurements.
//       The input parameters are 1: the hadronic mass

// Modification history:
//
//      Jim Libby October 11 2002
//------------------------------------------------------------------------
//

#include "EvtGenModels/EvtBtoXsgammaFixedMass.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtReport.hh"

#include "EvtGenModels/EvtBtoXsgamma.hh"

#include <fstream>
#include <stdlib.h>
using std::endl;
using std::fstream;

void EvtBtoXsgammaFixedMass::init( int nArg, double* args )
{
    if ( ( nArg ) > 2 || ( nArg > 1 && nArg < 2 ) ) {
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "EvtBtoXsgamma generator model "
            << "EvtBtoXsgammaFixedMass expected "
            << "either 1(default config) or two arguments but found: " << nArg
            << endl;
        EvtGenReport( EVTGEN_ERROR, "EvtGen" )
            << "Will terminate execution!" << endl;
        ::abort();
    }

    if ( nArg == 1 ) {
        _mH = 2.0;
    } else {
        _mH = args[1];
    }
}

double EvtBtoXsgammaFixedMass::GetMass( int /*Xscode*/ )
{
    return _mH;
}
