#ifndef EVTMODEL_HH
#define EVTMODEL_HH

#include "EvtGenBase/EvtDecayBase.hh"
#include "EvtGenBase/EvtStringHash.hh"

#include <map>
//#include <fstream.h>

//Class to read in and handle the decays available
//to EvtGen for each particle, and the model to be
//used for each one.

class EvtModel {
  public:
    static EvtModel& instance();

    void registerModel( EvtDecayBase* prototype );

    int isModel( std::string name );

    EvtDecayBase* getFcn( std::string model_name );

    int isCommand( std::string cmd );
    void storeCommand( std::string cmd, std::string cnfgstr );

  private:
    EvtModel();

    static EvtModel* _instance;

    std::map<std::string, EvtDecayBase*> _modelNameHash;
    std::map<std::string, EvtDecayBase*> _commandNameHash;
};

inline EvtModel& EvtModel::instance()
{
    if ( _instance == 0 )
        _instance = new EvtModel;
    return *_instance;
}

#endif
