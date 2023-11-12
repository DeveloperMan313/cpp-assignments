#pragma once

#include "calculus.h"
#include <stdio.h>
#include <string.h>

#define COLUMN_NUMBER 4

struct I_print {
  const char *name;
  double i_sum;
  double i_toch;
  int n;
};

void printDividingLine(const char horizontalSybmol, const char connectorSybmol,
                       const int m, const int *wn);

void printTable(struct I_print i_prn[], int k);

void CalculatePrintTables(TCALC i_calc, const char *method_name, double a,
                          double b);
