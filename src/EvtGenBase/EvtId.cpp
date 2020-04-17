#include "EvtGenBase/EvtId.hh"

#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtPatches.hh"

#include <iostream>
using std::ostream;

ostream& operator<<( ostream& s, const EvtId& id )
{
    s << "(Id=" << id._id << " Alias=" << id._alias << ")";

    return s;
}

int EvtId::isConjugate( const EvtId& id ) const
{
    return EvtPDL::getStdHep( *this ) == -EvtPDL::getStdHep( id );
}

std::string EvtId::getName() const
{
    return EvtPDL::name( *this );
}
