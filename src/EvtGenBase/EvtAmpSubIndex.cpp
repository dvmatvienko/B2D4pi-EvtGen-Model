#include "EvtGenBase/EvtAmpSubIndex.hh"

#include "EvtGenBase/EvtAmpIndex.hh"
#include "EvtGenBase/EvtPatches.hh"

#include <vector>
using std::vector;

EvtAmpSubIndex::EvtAmpSubIndex( EvtAmpIndex* ind, std::vector<int> sub ) :
    _ind( ind ), _sub( sub ), _size( sub.size() ), _nstate( sub.size() )
{
    int i;

    for ( i = 0; i < _size; i++ ) {
        if ( i == 0 ) {
            _nstate[i] = 1;
        } else {
            _nstate[i] = _nstate[i - 1] * _ind->_ind[sub[i - 1]];
        }
    }
}

int EvtAmpSubIndex::index()
{
    int i;
    int ind = 0;

    for ( i = 0; i < _size; i++ ) {
        ind += _ind->_state[_ind->_ind[i]] * _nstate[i];
    }

    return ind;
}
