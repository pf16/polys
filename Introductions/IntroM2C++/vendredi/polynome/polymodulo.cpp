#include "polynome.h"
#include "modulo.h"

int main ()
{
  polynome<modulo<641> > p (1,1);
  polynome<double > q (1,1);
  p.coefficient(0) = -1;
  q.coefficient(0) = -1;
  for (int i = 0; i < 20; i++)
    cout << p.puissance(i) << endl << q.puissance(i) << endl;
}
