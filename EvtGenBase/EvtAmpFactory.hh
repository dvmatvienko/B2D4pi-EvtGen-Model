//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information:
//      Copyright (C) 1998      Caltech, UCSB
//
//    Alexei Dvoretskii     2001-2002
//------------------------------------------------------------------------

// Abstract amplitude factory parameterized by a vector of
// strings. Derived classes construct the amplitude, and PDFs for sampling
// points.

#ifndef EVT_AMP_FACTORY_HH
#define EVT_AMP_FACTORY_HH

#include "EvtGenBase/EvtAmpPdf.hh"
#include "EvtGenBase/EvtAmplitudeSum.hh"
#include "EvtGenBase/EvtMacros.hh"
#include "EvtGenBase/EvtMultiChannelParser.hh"
#include "EvtGenBase/EvtPdfMax.hh"
#include "EvtGenBase/EvtPdfSum.hh"

#include <stdio.h>
#include <string>
#include <vector>

template <class T>
class EvtAmpFactory {
  public:
    EvtAmpFactory() = default;

  protected:
    EvtAmpFactory( EvtAmpFactory<T>&& ) = default;
    EvtAmpFactory( const EvtAmpFactory<T>& other ) :
        _amp( other._amp ? other._amp->clone() : nullptr ),
        _ampConj( other._ampConj ? other._ampConj->clone() : nullptr ),
        _pc( other._pc ? other._pc->clone() : nullptr ),
        _names( other._names ),
        _dm( other._dm ),
        _mixPhase( other._mixPhase ),
        _verbose( other._verbose )
    {
    }

  public:
    virtual ~EvtAmpFactory() = default;

    virtual EvtAmpFactory<T>* clone() const = 0;

    virtual void build( const EvtMultiChannelParser& parser, int nItg )
    {
        _amp = std::make_unique<EvtAmplitudeSum<T>>();
        _ampConj = std::make_unique<EvtAmplitudeSum<T>>();
        _pc = std::make_unique<EvtPdfSum<T>>();
        _dm = parser.dm();
        _mixAmpli = parser.mixAmpli();
        _mixPhase = parser.mixPhase();

        printf( "Amplitude with %d terms\n", parser.getNAmp() );
        int i;
        for ( i = 0; i < parser.getNAmp(); i++ ) {
            std::vector<std::string> v = parser.amp( i );
            EvtComplex c = parser.ampCoef( i );
            processAmp( c, v );
        }

        printf( "Conj. amplitude with %d terms\n", parser.getNAmpConj() );
        for ( i = 0; i < parser.getNAmpConj(); i++ ) {
            std::vector<std::string> v = parser.ampConj( i );
            EvtComplex c = parser.ampConjCoef( i );
            processAmp( c, v, true );
        }

        printf( "Calculating pole compensator integrals %d steps\n", nItg );
        if ( nItg > 0 )
            _pc->getItg( nItg );

        printf( "End build\n" );
    }

    virtual void processAmp( EvtComplex c, std::vector<std::string> v,
                             bool conj = false ) = 0;

    inline bool isCPModel() const
    {
        return ( _ampConj->nTerms() > 0 ? true : false );
    }
    inline double dm() const { return _dm; }
    inline double mixAmpli() const { return _mixAmpli; }
    inline double mixPhase() const { return _mixPhase; }

    void setVerbose() { _verbose = true; }

    EvtAmplitudeSum<T>* getAmp() const { return _amp.get(); }
    EvtAmplitudeSum<T>* getAmpConj() const { return _ampConj.get(); }
    EvtPdfSum<T>* getPC() const { return _pc.get(); }
    EvtAmplitude<T>* getAmp( int i ) const { return _amp->getTerm( i ); }
    EvtPdf<T>* getPC( int i ) const { return _pc->getPdf( i ); }
    const char* compName( int i ) const { return _names[i].c_str(); }

    EvtComplex getCoeff( int i ) const { return _amp->c( i ); }

    double getTermCoeff( int i ) const { return abs2( _amp->c( i ) ); }
    double getTermCoeff( int type, int i, int j ) const
    {
        switch ( type ) {
            case 0:
                return 2 * real( _amp->c( i ) * conj( _amp->c( j ) ) );    //posre
            case 1:
                return -2 * real( _amp->c( i ) * conj( _amp->c( j ) ) );    //negre
            case 2:
                return -2 * imag( _amp->c( i ) * conj( _amp->c( j ) ) );    //posim
            case 3:
                return 2 * imag( _amp->c( i ) * conj( _amp->c( j ) ) );    //negim
            default:
                assert( 0 );
        }
    }

  protected:
    std::unique_ptr<EvtAmplitudeSum<T>> _amp;        // _owned_ amplitude
    std::unique_ptr<EvtAmplitudeSum<T>> _ampConj;    // _owned_ conjugate amplitude
    std::unique_ptr<EvtPdfSum<T>> _pc;               // _owned_ pole compensator
    std::vector<std::string> _names;    // names of partial amplitudes

    double _dm = 0;      // Mass difference for conjugate amplitude
    double _mixPhase;    // mixing phase
    double _mixAmpli;    // cpv in mixing
    bool _verbose = false;
};

#endif
