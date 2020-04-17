#include "EvtGenBase/EvtdFunction.hh"

#include "EvtGenBase/EvtPatches.hh"
#include "EvtGenBase/EvtdFunctionSingle.hh"

#include <assert.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

double EvtdFunction::d( int j, int m1, int m2, double theta )
{
    int m1p = m1;
    int m2p = m2;

    int signp = 1;
    //make |m2p|>|m1p|
    if ( abs( m2p ) < abs( m1p ) ) {
        int tmp = m1p;
        m1p = m2p;
        m2p = tmp;
        if ( ( m1p - m2p ) % 4 != 0 )
            signp = -signp;
    }

    //make m2p non-negative
    if ( m2p < 0 ) {
        m1p = -m1p;
        m2p = -m2p;
        if ( ( m1p - m2p ) % 4 != 0 )
            signp = -signp;
    }

    EvtdFunctionSingle df;

    df.init( j, m1p, m2p );

    double d = df.d( j, m1p, m2p, theta ) * signp;

    return d;
}
