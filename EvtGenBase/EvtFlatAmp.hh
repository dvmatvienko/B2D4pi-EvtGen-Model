/*******************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: EvtGenBase
 *    File: $Id: EvtFlatAmp.hh,v 1.2 2009-03-16 16:42:03 robbep Exp $
 *  Author: Alexei Dvoretskii, dvoretsk@slac.stanford.edu, 2001-2002
 *
 * Copyright (C) 2002 Caltech
 *******************************************************************************/

// Flat amplitude

#ifndef EVT_FLAT_AMP_HH
#define EVT_FLAT_AMP_HH

#include "EvtGenBase/EvtAmplitude.hh"

template <class T>
class EvtFlatAmp : public EvtAmplitude<T> {
  public:
    EvtFlatAmp() {}
    EvtFlatAmp( const EvtFlatAmp<T>& other ) : EvtAmplitude<T>( other ) {}
    virtual ~EvtFlatAmp() {}

    EvtAmplitude<T>* clone() const override
    {
        return new EvtFlatAmp<T>( *this );
    }
    EvtComplex amplitude( const T& ) const override
    {
        return EvtComplex( 1., 0. );
    }
};

#endif
