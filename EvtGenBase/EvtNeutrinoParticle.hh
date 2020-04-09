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
// Module: EvtGen/EvtNeutrinoParticle.hh
//
// Description:Class to describe neutrinos
//
// Modification history:
//
//    RYD     September 25, 1996         Module created
//
//------------------------------------------------------------------------

#ifndef EVTNEUTRINOPARTICLE_HH
#define EVTNEUTRINOPARTICLE_HH

#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtParticle.hh"
class EvtId;
class EvtVector4R;

class EvtNeutrinoParticle : public EvtParticle {
  public:
    EvtNeutrinoParticle() = default;
    void init( EvtId part_n, const EvtVector4R& p4 ) override;
    EvtDiracSpinor spParentNeutrino() const override;
    EvtDiracSpinor spNeutrino() const override;
    EvtSpinDensity rotateToHelicityBasis() const override;
    EvtSpinDensity rotateToHelicityBasis( double alpha, double beta,
                                          double gamma ) const override;

  private:
    EvtDiracSpinor spinor_rest;
    EvtDiracSpinor spinor_parent;

    EvtNeutrinoParticle( const EvtNeutrinoParticle& n );
    EvtNeutrinoParticle& operator=( const EvtNeutrinoParticle& n );
};
#endif
