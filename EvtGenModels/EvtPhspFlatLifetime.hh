#ifndef EVTPHSPFLATLIFETIME_HH
#define EVTPHSPFLATLIFETIME_HH

#include "EvtGenBase/EvtDecayIncoherent.hh"

class EvtParticle;

// Description:
//   Class to handle generic phase space decays not done
//   in other decay models, with a flat lifetime

class EvtPhspFlatLifetime : public EvtDecayIncoherent {
  public:
    /// Constructor
    EvtPhspFlatLifetime() : m_maxLifetime( 0. ){};

    /// Destructor
    virtual ~EvtPhspFlatLifetime(){};

    /// return name of the model
    std::string getName() override;

    /// Clone
    EvtDecayBase* clone() override;

    /// Compute maximum weight
    void initProbMax() override;

    /// Initialize the model
    void init() override;

    /// Perform the decay
    void decay( EvtParticle* p ) override;

  private:
    /// parameter of the model: maximum of the generated lifetime (in ps)
    double m_maxLifetime;
};

#endif
