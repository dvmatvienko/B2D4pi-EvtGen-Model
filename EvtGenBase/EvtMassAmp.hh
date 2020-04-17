#ifndef EVT_MASSAMP_HH
#define EVT_MASSAMP_HH

#include "EvtGenBase/EvtAmplitude.hh"
#include "EvtGenBase/EvtPoint1D.hh"
#include "EvtGenBase/EvtPropBreitWignerRel.hh"
#include "EvtGenBase/EvtTwoBodyVertex.hh"

// Relativistic lineshape for a two-body decay of a resonance to two
// pseudoscalars. The mass dependence of the width and the vertex factors
// are included in the calculation.

class EvtMassAmp : public EvtAmplitude<EvtPoint1D> {
  public:
    EvtMassAmp( const EvtPropBreitWignerRel& prop, const EvtTwoBodyVertex& vd );
    EvtMassAmp( const EvtMassAmp& other );
    EvtMassAmp& operator=( const EvtMassAmp& other );

    EvtComplex amplitude( const EvtPoint1D& p ) const override;

    EvtAmplitude<EvtPoint1D>* clone() const override
    {
        return new EvtMassAmp( *this );
    }

    void setBirthVtx( const EvtTwoBodyVertex& vb )
    {
        _vb = std::make_unique<EvtTwoBodyVertex>( vb );
    }

    void addBirthFact() { _useBirthFact = true; }
    void addDeathFact() { _useDeathFact = true; }
    void addBirthFactFF() { _useBirthFactFF = true; }
    void addDeathFactFF() { _useDeathFactFF = true; }

  private:
    EvtPropBreitWignerRel _prop;
    EvtTwoBodyVertex _vd;
    std::unique_ptr<EvtTwoBodyVertex> _vb;

    bool _useBirthFact;
    bool _useDeathFact;
    bool _useBirthFactFF;
    bool _useDeathFactFF;
};

#endif
