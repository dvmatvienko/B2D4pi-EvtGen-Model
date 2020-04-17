#ifndef EVTRARITASCHWINGERPARTICLE_HH
#define EVTRARITASCHWINGERPARTICLE_HH

#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtRaritaSchwinger.hh"

class EvtVector4R;

class EvtRaritaSchwingerParticle : public EvtParticle {
  public:
    EvtRaritaSchwingerParticle() = default;
    void init( EvtId id, const EvtVector4R& p4 ) override;
    void init( EvtId id, const EvtVector4R& p4, const EvtRaritaSchwinger&,
               const EvtRaritaSchwinger&, const EvtRaritaSchwinger&,
               const EvtRaritaSchwinger&, const EvtRaritaSchwinger&,
               const EvtRaritaSchwinger&, const EvtRaritaSchwinger&,
               const EvtRaritaSchwinger& );
    EvtRaritaSchwinger spRSParent( int ) const override;
    EvtRaritaSchwinger spRS( int ) const override;
    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtRaritaSchwinger _spinorRest[4];
    EvtRaritaSchwinger _spinor[4];
    EvtRaritaSchwingerParticle( const EvtRaritaSchwingerParticle& d );
    EvtRaritaSchwingerParticle& operator=( const EvtRaritaSchwingerParticle& d );
};
#endif
