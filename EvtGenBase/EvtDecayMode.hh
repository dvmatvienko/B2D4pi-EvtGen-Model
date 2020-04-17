#ifndef EVT_DECAY_MODE_HH
#define EVT_DECAY_MODE_HH

#include "EvtGenBase/EvtCyclic3.hh"

#include <iosfwd>
#include <string>
#include <vector>

class EvtDecayMode final {
  public:
    EvtDecayMode( const char* decay );
    EvtDecayMode( const EvtDecayMode& other );
    EvtDecayMode( std::string mother, std::vector<std::string> dau );

    const char* mother() const;
    int nD() const;
    const char* dau( int i ) const;

    std::ostream& print( std::ostream& ) const;

    // Frequent name combinations

    std::string m( EvtCyclic3::Pair i ) const;
    std::string q( EvtCyclic3::Pair i ) const;
    std::string dal( EvtCyclic3::Pair i, EvtCyclic3::Pair j ) const;
    std::string mode() const;

  private:
    std::string _mother;
    std::vector<std::string> _dau;
};

std::ostream& operator<<( std::ostream&, const EvtDecayMode& );

#endif
