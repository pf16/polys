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

double trapeze (double f(double), double a, double b, int niveau)
{
  if (niveau <= 0)
    return (b-a) * (f(a) + f(b)) / 2;
  double c = (a+b)/2;
  return trapeze (f, a, c, niveau-1) + trapeze (f, c, b, niveau - 1);
}

int main (int argc, const char * argv[])
{
  cout << "Valeur exacte: " << setprecision(17) << 1 - cos (1) << endl;
  for (int l = 0; l <= 25; ++l)
    cout << "Approximation " << l << ' ' << trapeze (sinus, 0, 1, l) << endl;
  cout << appels << " appels de la fonction\n";
  return 0;
}
