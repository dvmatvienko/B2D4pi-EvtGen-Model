#ifndef EVTDIRACPARTICLE_HH
#define EVTDIRACPARTICLE_HH

#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtParticle.hh"

class EvtId;
class EvtVector4R;

class EvtDiracParticle : public EvtParticle {
  public:
    EvtDiracParticle() = default;
    void init( EvtId part_n, const EvtVector4R& p4 ) override;
    void init( EvtId part_n, const EvtVector4R& p4, const EvtDiracSpinor&,
               const EvtDiracSpinor&, const EvtDiracSpinor&,
               const EvtDiracSpinor& );
    EvtDiracSpinor spParent( int i ) const override { return _spinorParent[i]; }
    EvtDiracSpinor sp( int i ) const override { return _spinorRest[i]; }
    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtDiracSpinor _spinorRest[2];
    EvtDiracSpinor _spinorParent[2];
    EvtDiracParticle( const EvtDiracParticle& d );
    EvtDiracParticle& operator=( const EvtDiracParticle& d );
};
#endif
