#ifndef EVTBLLNUL_HH
#define EVTBLLNUL_HH

#include "EvtGenBase/EvtDecayAmp.hh"

#include "EvtGenModels/EvtBLLNuLAmp.hh"

#include <string>

class EvtParticle;
class EvtbTosllMSFF;    // Form factor class

// Description: The header file for the model "BLLNUL" which simulates
//              the rare four-leptonic B-decays
//              B^-(p) -> ell^+(k_1) ell^-(k_2) neu (k_3) ell^-(k_4)

class EvtBLLNuL : public EvtDecayAmp {
  public:
    EvtBLLNuL();

    virtual std::string getName() override;
    virtual EvtDecayBase* clone() override;

    virtual void init() override;
    virtual void initProbMax() override;
    virtual void decay( EvtParticle* p ) override;

  private:
    EvtBLLNuLAmp calcAmp_;
};

#endif
