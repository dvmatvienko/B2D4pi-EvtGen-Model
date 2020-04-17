#ifndef EVTEXTERNALGENLIST_HH
#define EVTEXTERNALGENLIST_HH

#include "EvtGenBase/EvtAbsRadCorr.hh"
#include "EvtGenBase/EvtDecayBase.hh"

#include <list>

// Description: A factory type method to create engines for external physics
// generators like Pythia.

class EvtExternalGenList {
  public:
    EvtExternalGenList( bool convertPythiaCodes = false,
                        std::string pythiaXmlDir = "",
                        std::string photonType = "gamma",
                        bool useEvtGenRandom = true );

    virtual ~EvtExternalGenList();

    std::list<EvtDecayBase*> getListOfModels();

    EvtAbsRadCorr* getPhotosModel();

  protected:
  private:
};

#endif
