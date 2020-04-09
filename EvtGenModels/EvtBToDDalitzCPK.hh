#ifndef EVTGENMODELS_EVTBTODDALITZCPK_HH
#define EVTGENMODELS_EVTBTODDALITZCPK_HH 1

// Include files
#include "EvtGenBase/EvtDecayAmp.hh"

/** @class EvtBToDDalitzCPK EvtBToDDalitzCPK.hh EvtGenModels/EvtBToDDalitzCPK.hh
 *  Decay Model for B->DK, (adds the possibility to use D0->Ks pi pi to
 *  find gamma with a Dalitz analysis
 *
 *  @author Patrick Robbe
 *  @date   2003-12-08
 */

class EvtBToDDalitzCPK : public EvtDecayAmp {
  public:
    std::string getName() override;
    EvtBToDDalitzCPK* clone() override;

    void decay( EvtParticle* p ) override;
    void init() override;

    void initProbMax() override;

  private:
    int _flag;
};
#endif    // EVTGENMODELS_EVTBTODDALITZCPK_HH
