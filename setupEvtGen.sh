#!/bin/bash

# This script installs EvtGen with all external dependencies. The variable VERSION specifies the
# tag of EvtGen you want to use. The list of available tags can be found by either going to the url
# https://phab.hepforge.org/source/evtgen/tags/master
# or issuing the command (without the need to clone the git repository)
# git ls-remote --tags http://phab.hepforge.org/source/evtgen.git | cut -d '/' -f3
# Note that some earlier EvtGen versions will not be compatible with all external dependency
# versions given below, owing to C++ interface differences; see the specific tagged version of
# the EvtGen/README file for guidance.
# To obtain this script use the "Download File" option on the right of the webpage:
# https://phab.hepforge.org/source/evtgen/browse/master/setupEvtGen.sh?view=raw

# Version or tag number. No extra spaces on this line!
VERSION=smallerissuesav3
# Pythia version number with no decimal points, e.g. 8230 corresponds to version 8.230. This
# follows the naming convention of Pythia install tar files. Again, no extra spaces allowed
PYTHIAVER=8243
PYTHIAPKG="pythia"$PYTHIAVER
PYTHIATAR=$PYTHIAPKG".tgz"
echo Pythia version set to $PYTHIAVER, package tar name $PYTHIATAR

HEPMCMAJORVERSION="3"

#This is for systems with cmake and cmake3
if command -v cmake3; then
CMAKE=cmake3
else
CMAKE=cmake
fi


mkdir -p EvtGen
cd EvtGen

INSTALL_BASE=`pwd`

echo Will setup EvtGen $VERSION in $INSTALL_BASE

echo Downloading EvtGen from GIT
git clone https://phab.hepforge.org/source/evtgen.git evtgen.git
cd evtgen.git
#git checkout -b $VERSION $VERSION
git checkout $VERSION
cd $INSTALL_BASE
# Replace the above lines with the following one for the "head" version
#git clone http://phab.hepforge.org/source/evtgen.git evtgen.git

osArch=`uname`

echo Downloading external dependencies
mkdir -p external
cd external

if [ "$osArch" == "Darwin" ]
then
  export LANG=en_US.UTF-8
  export LC_ALL=en_US.UTF-8
fi
# Recommended versions of the external packages. HepMC is mandatory.
# Later versions should be OK as well, assuming their C++ interfaces do not change
curl -O http://hepmc.web.cern.ch/hepmc/releases/hepmc2.06.10.tgz
curl -O http://hepmc.web.cern.ch/hepmc/releases/HepMC3-3.2.0.tar.gz
curl -O http://home.thep.lu.se/~torbjorn/pythia8/$PYTHIATAR
curl -O http://photospp.web.cern.ch/photospp/resources/PHOTOS.3.64/PHOTOS.3.64.tar.gz
curl -O http://tauolapp.web.cern.ch/tauolapp/resources/TAUOLA.1.1.8/TAUOLA.1.1.8.tar.gz

echo Extracting external dependencies
tar -xzf hepmc2.06.10.tgz
tar -xzf HepMC3-3.2.0.tar.gz
tar -xzf $PYTHIATAR
tar -xzf PHOTOS.3.64.tar.gz
tar -xzf TAUOLA.1.1.8.tar.gz

# Patch TAUOLA and PHOTOS on Darwin (Mac)
if [ "$osArch" == "Darwin" ]
then
  sed -i '' 's/soname/install_name/g'  PHOTOS/Makefile
  sed -i '' 's/soname/install_name/g'  TAUOLA/Makefile
  patch -p0 < $INSTALL_BASE/evtgen.git/platform/tauola_Darwin.patch
  patch -p0 < $INSTALL_BASE/evtgen.git/platform/photos_Darwin.patch
# Uncomment the lines below to force usage of clang
#  export CC=clang
#  export CXX=clang++
#  sed -i '' 's/\-lstdc++/-lc++/g' PHOTOS/platform/make.inc.in
#  sed -i '' 's/\-lstdc++/-lc++/g' TAUOLA/platform/make.inc.in
fi


if [ "$HEPMCMAJORVERSION" -lt "3" ]
then
echo Installing HepMC in $INSTALL_BASE/external/HepMC
mkdir -p HepMC
mkdir -p HepMC.build
cd HepMC.build
$CMAKE -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/external/HepMC $INSTALL_BASE/external/HepMC-2.06.10 -Dmomentum:STRING=GEV -Dlength:STRING=MM
make
make install

echo Installing pythia8 in $INSTALL_BASE/external/$PYTHIAPKG
cd ../$PYTHIAPKG
./configure --enable-shared  --prefix=$INSTALL_BASE/external/$PYTHIAPKG

make
make install

echo Installing PHOTOS in $INSTALL_BASE/external/PHOTOS
cd ../PHOTOS
./configure --with-hepmc3= --with-hepmc=$INSTALL_BASE/external/HepMC --prefix=$INSTALL_BASE/external/PHOTOS
make
make install

if [ "$osArch" != "Darwin" ]
then
echo Installing TAUOLA in $INSTALL_BASE/external/TAUOLA
cd ../TAUOLA
./configure --without-hepmc3 --with-hepmc=$INSTALL_BASE/external/HepMC  --prefix=$INSTALL_BASE/external/TAUOLA
make
make install
fi

else

echo Installing HepMC3 in $INSTALL_BASE/external/HepMC3
mkdir -p HepMC3
mkdir -p HepMC3.build
cd HepMC3.build
$CMAKE  -DHEPMC3_ENABLE_ROOTIO=OFF -DHEPMC3_ENABLE_PYTHON=OFF -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/external/HepMC3 $INSTALL_BASE/external/HepMC3-3.2.0
make
make install

echo Installing pythia8 in $INSTALL_BASE/external/$PYTHIAPKG
cd ../$PYTHIAPKG
./configure --enable-shared  --prefix=$INSTALL_BASE/external/$PYTHIAPKG
make
make install

echo Installing PHOTOS in $INSTALL_BASE/external/PHOTOS
cd ../PHOTOS 
./configure --without-hepmc --with-hepmc3=$INSTALL_BASE/external/HepMC3 --prefix=$INSTALL_BASE/external/PHOTOS
make
make install 

if [ "$osArch" != "Darwin" ]
then
echo Installing TAUOLA in $INSTALL_BASE/external/TAUOLA
cd ../TAUOLA
./configure  --without-hepmc --with-hepmc3=$INSTALL_BASE/external/HepMC3 --prefix=$INSTALL_BASE/external/TAUOLA
make
make install 
fi
fi

echo Building EvtGen
cd $INSTALL_BASE
mkdir -p evtgen.build
mkdir -p evtgen
cd evtgen.build
if [ "$osArch" == "Darwin" ]
then

if [ "$HEPMCMAJORVERSION" -lt "3" ]
then
$CMAKE -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/evtgen $INSTALL_BASE/evtgen.git -DEVTGEN_PYTHIA=ON -DEVTGEN_PHOTOS=ON -DEVTGEN_TAUOLA=OFF -DEVTGEN_HEPMC3=OFF \
-DHEPMC2_ROOT_DIR=$INSTALL_BASE/external/HepMC \
-DPYTHIA8_ROOT_DIR=$INSTALL_BASE/external/$PYTHIAPKG \
-DPHOTOSPP_ROOT_DIR=$INSTALL_BASE/external/PHOTOS 
else
$CMAKE -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/evtgen $INSTALL_BASE/evtgen.git -DEVTGEN_PYTHIA=ON -DEVTGEN_PHOTOS=ON -DEVTGEN_TAUOLA=OFF -DEVTGEN_HEPMC3=ON \
-DHepMC3_DIR=$INSTALL_BASE/external/HepMC3/share/HepMC3/cmake/ \
-DPYTHIA8_ROOT_DIR=$INSTALL_BASE/external/$PYTHIAPKG \
-DPHOTOSPP_ROOT_DIR=$INSTALL_BASE/external/PHOTOS 
fi


else

if [ "$HEPMCMAJORVERSION" -lt "3" ]
then
$CMAKE -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/evtgen $INSTALL_BASE/evtgen.git -DEVTGEN_PYTHIA=ON -DEVTGEN_PHOTOS=ON -DEVTGEN_TAUOLA=ON -DEVTGEN_HEPMC3=OFF \
-DHEPMC2_ROOT_DIR=$INSTALL_BASE/external/HepMC \
-DPYTHIA8_ROOT_DIR=$INSTALL_BASE/external/$PYTHIAPKG \
-DPHOTOSPP_ROOT_DIR=$INSTALL_BASE/external/PHOTOS \
-DTAUOLAPP_ROOT_DIR=$INSTALL_BASE/external/TAUOLA 
else
$CMAKE -DCMAKE_INSTALL_PREFIX=$INSTALL_BASE/evtgen $INSTALL_BASE/evtgen.git -DEVTGEN_PYTHIA=ON -DEVTGEN_PHOTOS=ON -DEVTGEN_TAUOLA=ON -DEVTGEN_HEPMC3=ON \
-DHepMC3_DIR=$INSTALL_BASE/external/HepMC3/share/HepMC3/cmake/ \
-DPYTHIA8_ROOT_DIR=$INSTALL_BASE/external/$PYTHIAPKG \
-DPHOTOSPP_ROOT_DIR=$INSTALL_BASE/external/PHOTOS \
-DTAUOLAPP_ROOT_DIR=$INSTALL_BASE/external/TAUOLA
fi
fi
make
make install
cd $INSTALL_BASE/evtgen

echo Setup done.
echo To complete, set the Pythia8 data path:
if [ "$PYTHIAVER" -lt "8200" ]
then
  echo PYTHIA8DATA=$INSTALL_BASE/external/$PYTHIAPKG/xmldoc
else
  echo PYTHIA8DATA=$INSTALL_BASE/external/$PYTHIAPKG/share/Pythia8/xmldoc
fi
