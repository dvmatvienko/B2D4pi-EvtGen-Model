#ifndef EVTPYTHIA_HH
#define EVTPYTHIA_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

#include <string>
#include <vector>

class EvtParticle;
class EvtAbsExternalGen;
class EvtDecayBase;

// Description:
// Class to handle generic phase space decays not done
// in other decay models.

class EvtPythia : public EvtDecayIncoherent {
  public:
    EvtPythia();
    ~EvtPythia();

    std::string getName() override;

    EvtDecayBase* clone() override;

    void initProbMax() override;

    void init() override;

    void decay( EvtParticle* p ) override;

    std::string commandName() override;
    void command( std::string ) override;

  protected:
    EvtAbsExternalGen* _pythiaEngine;

  private:
    void fixPolarisations( EvtParticle* p );
    std::vector<std::string> _commandList;
};

#endif
