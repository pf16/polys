#include <iostream>
#include <cstdlib>
using namespace std;

bool premier (int);

int a[10][12];

int main (int argc, char *argv[])
{
 int **c = new int *[12];
 for (int i = 0; i < 12; i++)
   c[i] = new int[10];

  cout << argc << " arguments" << endl;
  for (int i = 0; i < argc; i++)
    cout << "  " << argv[i] << endl;

  int n = atoi(argv[1]);
  int nb = 0;
  
  for (int p = 2; p < n; p++)
    if (premier(p))
	nb++;
  cout << "Il y a " << nb << " nombres premiers inférieurs à " << n << endl;
  return 0;
}

bool premier (int p)
{
  for (int x = 2; x*x <= p; x++)
    if (p%x == 0)
      return false;
  return true;
}

