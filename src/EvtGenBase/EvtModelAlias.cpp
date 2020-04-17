#include "EvtGenBase/EvtModelAlias.hh"

#include "EvtGenBase/EvtPatches.hh"

EvtModelAlias::EvtModelAlias( std::string alias, std::string model,
                              std::vector<std::string> args ) :

    _aliasName( alias ), _model( model ), _modelArgs( args )

{
}

EvtModelAlias::EvtModelAlias( const EvtModelAlias& copyMe ) :

    _aliasName( copyMe._aliasName ),
    _model( copyMe._model ),
    _modelArgs( copyMe._modelArgs )

{
}

EvtModelAlias EvtModelAlias::operator=( const EvtModelAlias& copyMe )
{
    _aliasName = copyMe._aliasName;
    _model = copyMe._model;
    _modelArgs = copyMe._modelArgs;

    return *this;
}

std::vector<std::string> EvtModelAlias::getArgList()
{
    return _modelArgs;
}
