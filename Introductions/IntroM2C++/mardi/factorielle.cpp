#include <iostream>
using namespace std;


long long factorielle (int n)
{
  return (n < 2) ? 1 : n * factorielle (n-1);
}

int main ()
{
  for (int i = 0; i < 20; i++)
    cout << i << " " << factorielle(i) << endl;
  return 0;
}

