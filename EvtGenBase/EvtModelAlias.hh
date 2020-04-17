#ifndef EVTMODELALIAS_HH
#define EVTMODELALIAS_HH

#include <string>
#include <vector>

class EvtModelAlias {
  public:
    EvtModelAlias(){};
    EvtModelAlias( std::string alias, std::string model,
                   std::vector<std::string> args );
    ~EvtModelAlias(){};
    EvtModelAlias( const EvtModelAlias& copyMe );
    EvtModelAlias operator=( const EvtModelAlias& copyMe );
    bool matchAlias( const std::string& cand )
    {
        if ( cand == _aliasName )
            return true;
        return false;
    }
    std::string getName() { return _model; }
    std::vector<std::string> getArgList();

  private:
    std::string _aliasName;
    std::string _model;
    std::vector<std::string> _modelArgs;
};
#endif
