#include <iostream>
using namespace std;

#include "modulo.h"
#include "puissance.h"

int main()
{
  modulo<641> m(2);
  for (int i = 0; i < 100; i++)
    cout << i << ' ' << puissance(m, i) << endl;
}
