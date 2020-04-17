#ifndef EVTBTOSLLVECTORAMPNEW_HH
#define EVTBTOSLLVECTORAMPNEW_HH

#include "EvtGenModels/EvtbTosllAmpNew.hh"

class EvtId;
class EvtAmp;
class EvtParticle;
class EvtbTosllFFNew;
class EvtbTosllWilsCoeffNLO;

class EvtbTosllVectorAmpNew : public EvtbTosllAmpNew {
  public:
    EvtbTosllVectorAmpNew() {}

    //Daughters are initialized and have been added to the parent.
    //No need to carry around the daughters seperately!
    void CalcAmp( EvtParticle* parent, EvtAmp& amp, EvtbTosllFFNew* formFactors,
                  EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                  int res_swch, int ias, double CKM_A, double CKM_lambda,
                  double CKM_barrho, double CKM_bareta ) override;

    double CalcMaxProb( EvtId parnum, EvtId mesnum, EvtId l1num, EvtId l2num,
                        EvtbTosllFFNew* formFactors,
                        EvtbTosllWilsCoeffNLO* WilsCoeff, double mu, int Nf,
                        int res_swch, int ias, double CKM_A, double CKM_lambda,
                        double CKM_barrho, double CKM_bareta ) override;

    double lambda( double a, double b, double c ) override;
};

#endif
