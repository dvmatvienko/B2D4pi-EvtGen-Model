#!/usr/bin/env python

import sys
import ROOT

def compare1D(can, hist1, hist2):
  ''' Function to overlay two 1D histograms'''
  hist1.SetLineColor(ROOT.kBlue)
  hist2.SetLineColor(ROOT.kRed)
  hist1.Draw()
  hist2.Draw('same')
  can.Update()

def compare2D(can, hist1, hist2, pdf):
  ''' This function plots difference of 2D histograms. Be aware that in
case of identical histograms result will be empty plot.'''
  histDiff = hist1.Clone(hist1.GetName()+'diff')
  histDiff.Add(hist1, hist2, 1, -1)
  histDiff.SetMinimum(-50)
  histDiff.SetMaximum(50)
  histDiff.Draw('colz')
  can.Update()
  canvas.Print(pdf)

if __name__ == '__main__':
  file1 = ROOT.TFile.Open(sys.argv[1])
  file2 = ROOT.TFile.Open(sys.argv[2])
  pdfName = sys.argv[3]
  
  histNames = []
  histTypes = []
  
  for key in file1.GetListOfKeys():
    histNames.append(key.GetName())
    histTypes.append(key.GetClassName())
  
  print(histNames)
  print(histTypes)
  
  canvas = ROOT.TCanvas()
  canvas.Draw()
  canvas.Print(pdfName+'[')
  
  for name, typ in zip(histNames, histTypes):
    hh1 = file1.Get(name)
    hh2 = file2.Get(name)
    if 'TH1' in typ:
      compare1D(canvas, hh1, hh2)
      canvas.Print(pdfName)
    elif 'TH2' in typ:
      compare2D(canvas, hh1, hh2, pdfName)
    print(hh1.GetName())
    hh1.Chi2Test(hh2, "P")
  
  canvas.Print(pdfName+']')
  file1.Close()
  file2.Close()
  
