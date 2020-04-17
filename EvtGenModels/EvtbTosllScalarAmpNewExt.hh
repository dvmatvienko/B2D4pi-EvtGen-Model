#ifndef EVTBTOSLLSCALARAMPNEWEXT_HH
#define EVTBTOSLLSCALARAMPNEWEXT_HH

#include "EvtGenModels/EvtbTosllAmpNewExt.hh"

class EvtId;
class EvtAmp;
class EvtParticle;
class EvtbTosllFFNew;
class EvtbTosllWilsCoeffNLO;

class EvtbTosllScalarAmpNewExt : public EvtbTosllAmpNewExt {
  public:
    EvtbTosllScalarAmpNewExt() {}

    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp, EvtbTosllFFNew* formFactors,
                  EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                  int res_swch, int ias, double CKM_A, double CKM_lambda,
                  double CKM_barrho, double CKM_bareta, double ReA7,
                  double ImA7, double ReA10, double ImA10 ) override;

    double CalcMaxProb( EvtId parnum, EvtId mesnum, EvtId l1num, EvtId l2num,
                        EvtbTosllFFNew* formFactors,
                        EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                        int res_swch, int ias, double CKM_A, double CKM_lambda,
                        double CKM_barrho, double CKM_bareta, double ReA7,
                        double ImA7, double ReA10, double ImA10 ) override;

    double lambda( double a, double b, double c ) override;
};

#endif
