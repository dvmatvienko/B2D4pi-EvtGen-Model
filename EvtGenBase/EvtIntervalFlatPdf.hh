/*******************************************************************************
 * Project: BaBar detector at the SLAC PEP-II B-factory
 * Package: EvtGenBase
 *    File: $Id: EvtIntervalFlatPdf.hh,v 1.2 2009-03-16 16:42:03 robbep Exp $
 *  Author: Alexei Dvoretskii, dvoretsk@slac.stanford.edu, 2001-2002
 *
 * Copyright (C) 2002 Caltech
 *******************************************************************************/

/*
 * Uniform PDF defined on a 1D interval.
 */

#ifndef EVT_INTERVAL_FLAT_PDF_HH
#define EVT_INTERVAL_FLAT_PDF_HH

#include <assert.h>
#include "EvtGenBase/EvtPdf.hh"
#include "EvtGenBase/EvtPoint1D.hh"

class EvtIntervalFlatPdf : public EvtPdf<EvtPoint1D> {
public:

  EvtIntervalFlatPdf(double min, double max);
  EvtIntervalFlatPdf(const EvtIntervalFlatPdf& other);
  EvtPdf<EvtPoint1D>* clone() const override;

  using EvtPdf<EvtPoint1D>::compute_integral;
  EvtValError compute_integral() const override;
  EvtPoint1D randomPoint() override;

protected:

  double pdf(const EvtPoint1D&) const override;

  double _min;
  double _max;
};

#endif
