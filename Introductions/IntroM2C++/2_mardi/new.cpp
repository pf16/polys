#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main ()
{
  const int taille = 1000000000;
  typedef int block [taille];
  int *p;

  cout << "Taille d'un bloc " << sizeof(block) << endl;
  cout << "Taille d'un pointeur " << sizeof(p) << endl;
  
  for (int a = 1;; a++)
    {
      p = new block;
      if (p)
	{
	  for (int i = 0; i < taille; i++) 
	    p[i] = random();
	  cout << a << endl;
	}
      else
      {
	cout << "L'allocation " << a << " a échoué" << endl;
	break;
      }
      //      delete [] p;
    }

  return 0;
}
