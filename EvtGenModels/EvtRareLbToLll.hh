#ifndef EVTRARELBTOLLL_HH
#define EVTRARELBTOLLL_HH 1

// Include files

/** @class EvtRareLbToLll EvtRareLbToLll.hh EvtGenModels/EvtRareLbToLll.hh
 *
 *
 *  @author Thomas Blake
 *  @date   2013-11-27
 */

#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtDecayAmp.hh"
#include "EvtGenBase/EvtAmp.hh"

#include "EvtGenModels/EvtRareLbToLllFFBase.hh"
#include "EvtGenModels/EvtRareLbToLllWC.hh"
#include <memory>

class EvtRareLbToLll : public  EvtDecayAmp {

public:

  std::string getName() override;

  EvtDecayBase* clone() override;

  void init() override;

  void initProbMax() override;

  void decay( EvtParticle *parent ) override;

protected:

  void calcAmp( EvtAmp& amp, EvtParticle *parent ) ;

  void HadronicAmp( EvtParticle* parent,
                    EvtParticle* lambda,
                    EvtVector4C* T,
                    const  int i,
                    const  int j );

  void HadronicAmpRS( EvtParticle* parent,
                      EvtParticle* lambda,
                      EvtVector4C* T,
                      const  int i,
                      const  int j );

  bool isParticle( EvtParticle* parent ) const ;


private:

  double m_maxProbability;

  std::unique_ptr<EvtRareLbToLllFFBase> ffmodel_;
  std::unique_ptr<EvtRareLbToLllWC> wcmodel_;

};
#endif //
