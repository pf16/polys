// Version du 1er octobre 2013, Dominique Bernardi
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int appels;

double sinus (double x)
{
  appels++;
  return sin (x);
}

double trapeze (double f(double), double a, double b, int m)
{
  double s = (f(a) + f(b))/2, h = (b - a) / m;
  while ((a += h) < b)
    s += f(a);
  return h * s;
}

int main (int argc, const char * argv[])
{
  cout << "Valeur exacte: " << setprecision(17) << 1 - cos (1) << endl;
  for (int l = 0; l <= 25; ++l)
    cout << "Approximation " << l << ' ' << trapeze (sinus, 0, 1, 1<<l) << endl;
  cout << appels << " appels de la fonction\n";
  return 0;
}
