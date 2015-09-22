#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main ()
{
  int a = 7;
  int *pt = &a;
  delete pt;
  *pt = 12;
  cout << a << endl;
  pt = new int;
  *pt = 100;
  cout << a << endl;
  cout << *pt << endl;

  double table [6];
  for (int i = 0; i < 6; i++)
    table[i] = sin(i);

  table[2] = 7.1;

  cout << table[3] << endl;

  double *t;
  t = table;

  cout << *t << endl;
  cout << t[2] << endl;
  cout << *(t+2) << endl;

  double *u = &t[3];
  double *v = &t[1];
  int b = v - u;

  cout << "b " << b << endl;
  double *w = table + 4;
  cout << w[b] << endl;

  table[-100] = 1.;
  return 0;
}
