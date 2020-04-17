#ifndef EVTBSTOLLLL_HYPERCPAMP_HH
#define EVTBSTOLLLL_HYPERCPAMP_HH

class EvtId;
class EvtAmp;
class EvtParticle;

// Description: Preparation of the decay amplitude for the process:
//              B^0_{q}(p,M1) -> ell^+(k1,m) ell^-(k2,m) ell^+(k3,m) ell^-(k4,m)
//              in the HyperCP model.
//
//              [1] D.S.Gorbunov, Nucl.Phys.B602, pp.213-237 (2001);
//              [2] S.V. Demidov, D.S.Gorbunov, hep-ph/1112.5230v2, 17 April 2012.
//
// Note: The code of this module is based on the EvtbsToLLLLAmp.cpp module code.

class EvtbsToLLLLHyperCPAmp {
  public:
    void CalcAmp( EvtParticle* parent, EvtAmp& amp, double mS, double mP,
                  double gammaS, double gammaP, double mLiiLR, double Fc,
                  double mD23LL, double mD23RR, double mD32LL, double mD32RR,
                  double mD13LL, double mD13RR, double mD31LL, double mD31RR );

    double CalcMaxProb( EvtId parnum, EvtId l1num, EvtId l2num, EvtId l3num,
                        EvtId l4num, double mS, double mP, double gammaS,
                        double gammaP, double mLiiLR, double Fc, double mD23LL,
                        double mD23RR, double mD32LL, double mD32RR,
                        double mD13LL, double mD13RR, double mD31LL,
                        double mD31RR );

    double lambda( double a, double b, double c );
};

#endif
