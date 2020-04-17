#include "EvtGenBase/EvtSimpleRandomEngine.hh"

#include "EvtGenBase/EvtPatches.hh"

#include <iostream>
#include <math.h>
#include <stdio.h>

double EvtSimpleRandomEngine::random()
{
    _next = _next * 1103515245 + 123345;
    unsigned temp = (unsigned)( _next / 65536 ) % 32768;

    return ( temp + 1.0 ) / 32769.0;
}
