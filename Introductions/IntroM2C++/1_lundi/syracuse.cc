#include <iostream>
using namespace std;

int syracuse (int n)
{
  if (n > 1000000000)
    abort ();
  return (n % 2) ? (3 * n + 1) : (n / 2);
}

void deroule (int n)
{
  for (;;)
    {
      cout << n << ' ';
      if (n == 1)
	break;
      n = syracuse (n);
    }
  cout << endl;
}

int main ()
{
  int n;
  for (;;)
    {
      cin >> n;
      if (n <= 0)
	return 0;
      deroule (n);
    }
}
