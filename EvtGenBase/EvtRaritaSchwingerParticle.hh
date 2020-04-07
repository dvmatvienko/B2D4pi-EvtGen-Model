//--------------------------------------------------------------------------
//
// Environment:
//      This software is part of the EvtGen package developed jointly
//      for the BaBar and CLEO collaborations.  If you use all or part
//      of it, please give an appropriate acknowledgement.
//
// Copyright Information: See EvtGen/COPYRIGHT
//      Copyright (C) 1998      Caltech, UCSB
//
// Module: EvtGen/EvtRaritaSchwingerParticle.hh
//
// Description:Represents particles i.e. spin 3/2 particles.
//
// Modification history:
//
//    RYD     August 9, 2000         Module created
//
//------------------------------------------------------------------------

#ifndef EVTRARITASCHWINGERPARTICLE_HH
#define EVTRARITASCHWINGERPARTICLE_HH

#include "EvtGenBase/EvtRaritaSchwinger.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtParticle.hh"

class EvtVector4R;

class EvtRaritaSchwingerParticle:public EvtParticle {

public:


  EvtRaritaSchwingerParticle() = default;
  void init(EvtId id,const EvtVector4R& p4) override;
  void init(EvtId id,const EvtVector4R& p4,
	    const EvtRaritaSchwinger &,const EvtRaritaSchwinger &,
	    const EvtRaritaSchwinger &,const EvtRaritaSchwinger &,
	    const EvtRaritaSchwinger &,const EvtRaritaSchwinger &,
	    const EvtRaritaSchwinger &,const EvtRaritaSchwinger &);
  EvtRaritaSchwinger spRSParent(int) const override;
  EvtRaritaSchwinger spRS(int) const override;
  EvtSpinDensity rotateToHelicityBasis() const override;
  EvtSpinDensity rotateToHelicityBasis(double alpha,
				       double beta,
				       double gamma) const override;

private:

  EvtRaritaSchwinger _spinorRest[4];
  EvtRaritaSchwinger _spinor[4];
  EvtRaritaSchwingerParticle(const EvtRaritaSchwingerParticle& d);
  EvtRaritaSchwingerParticle& operator=(const EvtRaritaSchwingerParticle& d);

};
#endif

