#ifndef EVTBTOSLLAMPNEWEXT_HH
#define EVTBTOSLLAMPNEWEXT_HH
class EvtAmp;
class EvtId;
class EvtbTosllFFNew;
class EvtParticle;
class EvtbTosllWilsCoeffNLO;

// all definicions !
class EvtbTosllAmpNewExt {
  public:
    virtual ~EvtbTosllAmpNewExt(){};

    virtual void CalcAmp( EvtParticle* parent, EvtAmp& amp,
                          EvtbTosllFFNew* formFactors,
                          EvtbTosllWilsCoeffNLO* WilsCoeff, double /* mu */,
                          int /* Nf */, int /* res_swch */, int /* ias */,
                          double /* CKM_A */, double /* CKM_lambda */,
                          double /* CKM_barrho */, double /* CKM_bareta */,
                          double /* ReA7 */, double /* ImA7 */,
                          double /* ReA10 */, double /*ImA10 */ ) = 0;

    virtual double CalcMaxProb( EvtId /* parnum */, EvtId /* mesnum */,
                                EvtId /* l1num */, EvtId /* l2num */,
                                EvtbTosllFFNew* /* formFactors */,
                                EvtbTosllWilsCoeffNLO* /*WilsCoeff */,
                                double /* mu */, int /* Nf */,
                                int /* res_swch */, int /* ias */,
                                double /* CKM_A */, double /* CKM_lambda */,
                                double /* CKM_barrho */, double /* CKM_bareta */,
                                double /* ReA7 */, double /* ImA7 */,
                                double /* ReA10 */, double /*ImA10 */ )
    {
        return 0.0;
    };

    virtual double lambda( double /* a */, double /* b */, double /* c */ )
    {
        return 0.0;
    };
};

#endif
