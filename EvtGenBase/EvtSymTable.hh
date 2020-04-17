#ifndef EVTSYMTABLE_HH
#define EVTSYMTABLE_HH

#include <map>
#include <string>

// Description: Class to hold the symbols that are defined
//              in the DECAY files.

class EvtSymTable {
  public:
    EvtSymTable();
    ~EvtSymTable();

    static void define( const std::string& name, std::string d );

    static std::string get( const std::string& name, int& ierr );

  private:
    static std::map<std::string, std::string> _symMap;
};

#endif
