#ifndef EVT_ABS_BINNING_HH
#define EVT_ABS_BINNING_HH
#define BIN_OUTSIDE -1

#include <stdio.h>

/*
 * Data point to bin value mapping
 */

template <class T>
class EvtAbsBinning {
  public:
    EvtAbsBinning() {}
    EvtAbsBinning( const EvtAbsBinning<T>& other ) {}
    virtual ~EvtAbsBinning() {}

    virtual EvtAbsBinning<T>* clone() const = 0;
    virtual int getBin( const T& point ) const = 0;
    virtual T getBinPoint( int bin ) const = 0;
    virtual double size( int bin ) const = 0;

    virtual int nTypes() const = 0;

    virtual char* typeLabel( int i ) const
    {
        char* a = new char[128];
        sprintf( a, "%d", i );
        return a;
    }
};

#endif
