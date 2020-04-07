#!/usr/bin/bash

oldDir=$1
newDir=$2
pdfDir=$3

# First we do all root files
for ff in ${oldDir}/*root
do
  fileName=$(basename $ff)
  baseFileName=`echo ${fileName}|cut -d'.' -f1`
  ./compareRootFiles.py ${oldDir}/${fileName} ${newDir}/${fileName} ${pdfDir}/${baseFileName}.pdf
done

# Now compare all dat files
for ff in ${oldDir}/*dat
do
  fileName=$(basename ${ff})
  echo $fileName `diff ${oldDir}/${fileName} ${newDir}/${fileName}|wc -l `
done

