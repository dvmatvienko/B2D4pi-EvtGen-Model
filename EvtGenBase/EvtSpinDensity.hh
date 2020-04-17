#ifndef EVTSPINDENSITY_HH
#define EVTSPINDENSITY_HH
#include "EvtGenBase/EvtComplex.hh"

// Description: This class holds a spin density matrix, it is
//              a complex nxn matrix.

class EvtSpinDensity {
  public:
    EvtSpinDensity( const EvtSpinDensity& density );
    EvtSpinDensity& operator=( const EvtSpinDensity& density );
    virtual ~EvtSpinDensity();

    EvtSpinDensity();
    void setDim( int n );
    int getDim() const;
    void set( int i, int j, const EvtComplex& rhoij );
    const EvtComplex& get( int i, int j ) const;
    double normalizedProb( const EvtSpinDensity& d );
    friend std::ostream& operator<<( std::ostream& s, const EvtSpinDensity& d );
    void setDiag( int n );

    int check();

  private:
    EvtComplexPtrPtr rho;
    int dim;
};

#endif
