#include <iostream>
#include <iomanip>

using namespace std;

#include "Permutation.h"

int main()
{
  Permutation s(4);
  int nb = 1;
  do
    {
      cout << setw(2) << nb++
	   << " signature: " << setw(2) << s.signature()
	   << " ordre: " << s.ordre() << endl
	   << "   permutation: " << s  << " cycles: ";
      s.printCycles(cout);
      cout << endl;
    }
  while (s.next());
  cout << endl;

  Permutation t(4);
  t.next(); t.next(); t.next();
  Permutation u = t;
  u = s;
  cout << s << endl << t << endl << s * t << endl << endl;
  Permutation v(5);
  for (int i = 0; i < 10; i++)
    {
      v.rand();
      cout << v << endl;
    }
  return 0;
}
