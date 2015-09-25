#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <numeric>      // std::accumulate

using namespace std;

int pi (int n)
{
  vector<bool> prime(n, true);
  for (int p =2; p * p < n; ++p)
    if (prime[p])
      for (int q = p * p; q < n; q += p)
	(prime[q]) = false;
  return accumulate (prime.begin() + 2, prime.end(), 0);
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
