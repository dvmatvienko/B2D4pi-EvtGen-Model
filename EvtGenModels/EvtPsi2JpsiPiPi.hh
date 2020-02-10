//--------------------------------------------------------------------------
//
// Copyright Information: See EvtGen/COPYRIGHT
//
// Module: EvtPsi2JpsiPiPi.hh
//
// Description: Header file for the model "PSI2JPSIPIPI" which generates
//              psi2S -> J/psi pi+ pi- decays based on hep-ph/1507.07985
//
// Modification history: A Luchinsky    Nov 2019     Module created
//
//------------------------------------------------------------------------

#ifndef EVTPSI2JPSIPIPI_HH
#define EVTPSI2JPSIPIPI_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include <array>
#include <string>

class EvtDecayBase;
class EvtParticle;

class EvtPsi2JpsiPiPi : public EvtDecayAmp {
public:
    
    EvtPsi2JpsiPiPi();

    std::string getName() override;
    EvtDecayBase* clone() override;
    void initProbMax() override;
    void init() override;
    void decay(EvtParticle *p) override;

private:

    bool tree;
    double phi; // LO vs NLO mixing angle (radians)
    double cosPhi, cos2Phi, sinPhi, sin2Phi;
    // NLO corrections
    static const int nQ = 6; // number of terms in mPiPi interpolation
    std::array<double, nQ> c0, c1, c2, s1, s2;

    void setNLOArrays();

};

#endif
