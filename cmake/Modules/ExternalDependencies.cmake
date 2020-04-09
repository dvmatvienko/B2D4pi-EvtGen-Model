
set(HEPMC2_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of HepMC 2 installation")
set(HEPMC3_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of HepMC 3 installation")

set(PYTHIA8_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of Pythia8 installation")
set(Photos++_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of Photos++ installation")
set(Tauola++_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of Tauola++ installation")
set(PHOTOSPP_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of Photos++ installation - alternative spelling")
set(TAUOLAPP_ROOT_DIR "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Location of Tauola++ installation - alternative spelling")

# The components we search for in the external generators depend on the version
# of HepMC we're working with
if(EVTGEN_HEPMC3)
    find_package(HepMC3 REQUIRED PATHS ${HEPMC3_ROOT_DIR})
    if(EVTGEN_PYTHIA)
        find_package(Pythia8 REQUIRED)
    endif()
    if(EVTGEN_PHOTOS)
        # From version 3.64 Photos has HepMC3 support
        find_package(Photos++ REQUIRED COMPONENTS pp ppHepMC3)
    endif()
    if(EVTGEN_TAUOLA)
        # From version 1.1.8 Tauola has HepMC3 support
        find_package(Tauola++ REQUIRED COMPONENTS Fortran CxxInterface HepMC3)
    endif()
else()
    find_package(HepMC2 REQUIRED)
    if(EVTGEN_PYTHIA)
        find_package(Pythia8 REQUIRED)
    endif()
    if(EVTGEN_PHOTOS)
        # Photos has different library structures for versions before and after 3.58
        # so we need to search for either option: pp+ppHepMC or CxxInterface+Fortran
        find_package(Photos++ REQUIRED OPTIONAL_COMPONENTS pp ppHepMC CxxInterface Fortran)
    endif()
    if(EVTGEN_TAUOLA)
        # Older versions of Tauola don't have the HepMC component, the HepMC2 interface is in CxxInterface
        find_package(Tauola++ REQUIRED COMPONENTS Fortran CxxInterface OPTIONAL_COMPONENTS HepMC)
    endif()
endif()
