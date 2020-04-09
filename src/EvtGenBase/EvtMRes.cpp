#include "EvtGenBase/EvtMRes.hh"

#include "EvtGenBase/EvtPatches.hh"

EvtMRes::~EvtMRes()
{
    for ( size_t i = 0; i < _children.size(); ++i )
        delete _children[i];
}
