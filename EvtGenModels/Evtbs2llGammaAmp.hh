#ifndef EVTBSTOLLGAMMA_AMP_HH
#define EVTBSTOLLGAMMA_AMP_HH

class EvtId;
class EvtAmp;
class EvtParticle;
class Evtbs2llGammaFF;
class EvtbTosllWilsCoeffNLO;

// Description: Preparation of the decay amplitude for the process:
//              B^0_{q}(p,M1) -> gamma(k) ell^+(p1,m) ell^-(p2,m).
//
// Note: The code of this module is based on the EvtbTosllVectorAmp.cpp
//	 module code.
//	 The main functiom for the amplitude calculation retuns the
//	 amplitude for the decay  B -> gamma ell^+ ell^-
//	 In our calculations we assume, that photon is the first
//       daughter particle (iG=0) and leptons are the second and thirds
//       daughter particles (il1=1 and il2=2).

class Evtbs2llGammaAmp {
  public:
    void CalcAmp( EvtParticle* parent, EvtAmp& amp, Evtbs2llGammaFF* formFactors,
                  EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                  int res_swch, int ias, double Egamma_min, double CKM_A,
                  double CKM_lambda, double CKM_barrho, double CKM_bareta );

    double CalcMaxProb( EvtId parnum, EvtId photnum, EvtId l1num, EvtId l2num,
                        Evtbs2llGammaFF* formFactors,
                        EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                        int res_swch, int ias, double Egamma_min, double CKM_A,
                        double CKM_lambda, double CKM_barrho, double CKM_bareta );

    double lambda( double a, double b, double c );
};

#endif
