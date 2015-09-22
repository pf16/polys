#include <iostream>
#include <cstdlib>
using namespace std;

void crible (bool *table, int borne)
{
  for (int i = 0; i < borne; i++)
    table[i] = true;
  for (int i = 2; i * i < borne; i++)
    if (table[i])
      for (int j = i * i; j < borne; j += i)
	table[j] = false;
}

int main (int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int nb = 0;
  
  bool *t = new bool[n];
  crible(t, n);
  for (int p = 2; p < n; p++)
    if (t[p])
      nb++;
  cout << "Il y a " << nb << " nombres premiers inférieurs à " << n << endl;
  delete [] t;
  return 0;
}


