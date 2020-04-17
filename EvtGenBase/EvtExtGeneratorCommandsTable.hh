#include <map>
#include <string>
#include <vector>

#ifndef EVTEXTGENERATORCOMMANDSTABLE_HH
#define EVTEXTGENERATORCOMMANDSTABLE_HH

typedef std::map<std::string, std::string> Command;
typedef std::vector<Command> GeneratorCommands;
typedef std::map<std::string, GeneratorCommands> GlobalCommandMap;

class EvtExtGeneratorCommandsTable {
  public:
    static EvtExtGeneratorCommandsTable* getInstance();

    void addCommand( std::string extGenerator, Command command )
    {
        _commandMap[extGenerator].push_back( command );
    }
    const GeneratorCommands& getCommands( std::string extGenerator )
    {
        return _commandMap[extGenerator];
    }

  protected:
    EvtExtGeneratorCommandsTable();
    ~EvtExtGeneratorCommandsTable();

  private:
    GlobalCommandMap _commandMap;

    EvtExtGeneratorCommandsTable( const EvtExtGeneratorCommandsTable& ){};
};

#endif
