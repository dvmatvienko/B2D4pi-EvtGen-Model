#include "EvtGenBase/EvtAmpIndex.hh"

#include "EvtGenBase/EvtPatches.hh"

#include <vector>
using std::vector;

EvtAmpIndex::EvtAmpIndex( std::vector<int> ind ) :
    _ind( ind ), _size( ind.size() ), _state( ind.size() ), _nstate( ind.size() )
{
    int i;

    for ( i = 0; i < _size; i++ ) {
        _state[i] = 0;
        if ( i == 0 ) {
            _nstate[i] = 1;
        } else {
            _nstate[i] = _nstate[i - 1] * _ind[i];
        }
    }
}

void EvtAmpIndex::reset()
{
    int i;
    for ( i = 0; i < _size; i++ ) {
        _state[i] = 0;
    }
}

bool EvtAmpIndex::next()
{
    int i;
    for ( i = 0; i < _size; i++ ) {
        _state[i]++;
        if ( _state[i] < _ind[i] ) {
            return true;
        } else {
            _state[i] = 0;
        }
    }
    return false;
}

int EvtAmpIndex::index()
{
    int i;
    int ind = 0;

    for ( i = 0; i < _size; i++ ) {
        ind += _state[i] * _nstate[i];
    }

    return ind;
}
