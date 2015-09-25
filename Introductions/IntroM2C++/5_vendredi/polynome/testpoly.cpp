#include "polynome.h"
#include "puissance.h"
#include "modulo.h"

typedef modulo<65537> bidule;

int main ()
{
  polynome<double> p (1,1);
  p.coefficient(0) = -1;
  for (int i = 0; i < 10; i++)
    cout << puissance(p,i) << endl;
  polynome<double> q = p*p;
  cout << q << endl << q(q) << endl << endl;

  polynome<modulo<65537> > r(3,5);
  // polynome<bidule> r(3, 5);
  r.coefficient(0) = 7;
  for (int i = 0; i < 10; i++)
    cout << puissance(r,i) << endl;
  polynome<bidule> s = r*r;
  cout << r << endl << r(r) << endl;

}
