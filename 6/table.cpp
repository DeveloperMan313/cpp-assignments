#include "table.hpp"

using namespace std;

void printDividingLine(const char horizontalSybmol, const char connectorSybmol,
                       const int m, const int *wn) {
  putchar(connectorSybmol);
  for (int line_i = 0; line_i < m; line_i++) {
    for (int line_j = 0; line_j < wn[line_i]; line_j++) {
      putchar(horizontalSybmol);
    }
    putchar(connectorSybmol);
  }
  putchar('\n');
}

void printTable(struct I_print i_prn[], int k) {
  const char SIDE_SYBMOL = '|';
  const char HORIZONTAL_SYBMOL = '-';
  const char CONNECTOR_SYBMOL = '+';

  int wn[COLUMN_NUMBER] = {12, 18, 18, 10};
  char *title[COLUMN_NUMBER] = {(char *)"Function", (char *)"Integral",
                                (char *)"IntSum", (char *)"N "};
  int size[COLUMN_NUMBER];
  for (int i = 0; i < COLUMN_NUMBER; i++) {
    size[i] = (int)strlen(title[i]);
  }

  printDividingLine(HORIZONTAL_SYBMOL, CONNECTOR_SYBMOL, COLUMN_NUMBER, wn);

  putchar(SIDE_SYBMOL);
  for (int line_i = 0; line_i < COLUMN_NUMBER; line_i++) {
    int half = (wn[line_i] - size[line_i]) / 2;
    for (int line_j = 0; line_j < half; line_j++) {
      putchar(' ');
    }
    printf("%s", title[line_i]);
    for (int line_j = 0; line_j < half; line_j++) {
      putchar(' ');
    }
    putchar(SIDE_SYBMOL);
  }
  putchar('\n');

  printDividingLine(HORIZONTAL_SYBMOL, CONNECTOR_SYBMOL, COLUMN_NUMBER, wn);

  for (int i = 0; i < k; i++) {
    putchar(SIDE_SYBMOL);
    printf("%12s", i_prn[i].name);
    putchar(SIDE_SYBMOL);

    char i_toch[64];
    sprintf(i_toch, "%.10f", i_prn[i].i_toch);
    printf("%18s", i_toch);
    putchar(SIDE_SYBMOL);

    char i_sum[64];
    sprintf(i_sum, "%.10f", i_prn[i].i_sum);
    printf("%18s", i_sum);
    putchar(SIDE_SYBMOL);

    printf("%10d", i_prn[i].n);
    putchar(SIDE_SYBMOL);
    putchar('\n');
    printDividingLine(HORIZONTAL_SYBMOL, CONNECTOR_SYBMOL, COLUMN_NUMBER, wn);
  }
}

void CalculatePrintTables(TCALC i_calc, const char *method_name, double a,
                          double b) {
  const int f_count = 4;
  const TPF funcs[] = {f1, f2, f3, f4};
  const TIF funcs_pr[] = {f1_i, f2_i, f3_i, f4_i};
  const char *f_names[] = {"y=x", "y=sin(22x)", "y=x^4", "y=arctg(x)"};
  double eps = 0.1;
  for (int i = 0; i < 5; ++i) {
    eps *= 0.1;
    I_print i_prn[f_count];
    for (int j = 0; j < f_count; ++j) {
      int n;
      const double i_calculated = i_calc(funcs[j], a, b, eps, &n);
      i_prn[j] = {f_names[j], i_calculated, funcs_pr[j](a, b), n};
    }
    cout << method_name << ". eps = " << eps << endl;
    printTable(i_prn, f_count);
    cout << endl;
  }
}
