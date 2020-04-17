#ifndef EVTPHOTONPARTICLE_HH
#define EVTPHOTONPARTICLE_HH

#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtVector4C.hh"
class EvtId;

//Class to handle massless spin 1 particles.

class EvtPhotonParticle : public EvtParticle {
  public:
    EvtPhotonParticle() = default;

    void init( EvtId part_n, double e, double px, double py, double pz );
    void init( EvtId part_n, const EvtVector4R& p4 ) override;

    //Return polarization vectors
    EvtVector4C epsParentPhoton( int i ) override;
    EvtVector4C epsPhoton( int i ) override;

    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtVector4C eps1, eps2;
    int _evalBasis;

    EvtPhotonParticle( const EvtPhotonParticle& photon );
    EvtPhotonParticle& operator=( const EvtPhotonParticle& photon );
};

#endif
