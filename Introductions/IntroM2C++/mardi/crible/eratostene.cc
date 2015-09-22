#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

bool *crible (int n)
{
  bool *primes = new bool[n];

  for (int i = 2; i < n; i++)
    primes[i] = true;
  primes[0] = primes[1] = false;
  for (int p = 2; p * p < n; p++)
    if (primes[p])
      for (int q = p * p; q < n; q+=p)
	primes[q] = false;
  return primes;
}

int pi(int n)
{
  int nb = 0;
  bool *prime = crible (n + 1);
  for (int i = 0; i <= n; i++)
    if (prime[i]) nb++;
  delete [] prime;
  return nb;
}

int main ()
{
  int m = 1;
  for (int k = 1; k <= 9; k++)
    {
      m *= 10;
      int nb = pi (m);
      cout << "Il y a " << setw(9) << nb 
	   << " premiers inférieurs ou égaux à " << m
	   << " ratio " << nb * log (m) / m << endl ;
    }
  return 0;
}
