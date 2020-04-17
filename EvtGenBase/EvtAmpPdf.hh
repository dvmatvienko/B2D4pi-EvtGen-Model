#ifndef EVT_AMP_PDF_HH
#define EVT_AMP_PDF_HH

#include "EvtGenBase/EvtAmplitude.hh"
#include "EvtGenBase/EvtMacros.hh"
#include "EvtGenBase/EvtPdf.hh"

template <class T>

class EvtAmpPdf : public EvtPdf<T> {
  public:
    EvtAmpPdf() {}
    EvtAmpPdf( const EvtAmplitude<T>& amp ) : EvtPdf<T>(), _amp( amp.clone() )
    {
    }
    EvtAmpPdf( const EvtAmpPdf<T>& other ) :
        EvtPdf<T>( other ), COPY_PTR( _amp )
    {
    }
    virtual ~EvtAmpPdf() { delete _amp; }

    EvtAmpPdf<T>* clone() const override { return new EvtAmpPdf( *this ); }

    double pdf( const T& p ) const override
    {
        EvtComplex amp = _amp->evaluate( p );
        return real( amp ) * real( amp ) + imag( amp ) * imag( amp );
    }

  private:
    EvtAmplitude<T>* _amp;
};

#endif
