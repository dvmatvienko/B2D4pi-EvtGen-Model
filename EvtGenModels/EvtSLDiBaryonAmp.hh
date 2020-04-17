#ifndef EVTSLDIBARYONAMP_HH
#define EVTSLDIBARYONAMP_HH

#include "EvtGenBase/EvtAmp.hh"
#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtId.hh"
#include "EvtGenBase/EvtVector4C.hh"
#include "EvtGenBase/EvtVector4R.hh"

#include "EvtGenModels/EvtBToDiBaryonlnupQCDFF.hh"

#include <vector>

class EvtParticle;

// Description: Routine to implement semileptonic decays to dibaryonic final
// state. Details of amplitude calculation to be found in arXiv:1107.0801.

class EvtSLDiBaryonAmp {
  public:
    EvtSLDiBaryonAmp( const EvtBToDiBaryonlnupQCDFF& );

    void CalcAmp( EvtParticle* parent, EvtAmp& amp ) const;

  protected:
    int checkDibaryonParity( const EvtId& id1, const EvtId& id2, const int J1,
                             const int J2 ) const;

    int getBaryonParity( const EvtId& id ) const;

    std::vector<EvtVector4C> getHadronicCurrents(
        const EvtDiracSpinor& u, const EvtDiracSpinor& v, const EvtVector4R& p,
        const EvtVector4R& gMtmTerms, const EvtVector4R& fMtmTerms ) const;

  private:
    EvtBToDiBaryonlnupQCDFF ffModel_;
};

#endif
