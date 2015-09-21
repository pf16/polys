#include <iostream>
#include <complex>
using namespace std;

int main ()
{
  int a = 12;
  long long b = 123456789123456789;
  bool c = true;
  float d = 1.2;
  double e = 22./7;
  char f = 'x';
  const char *g = "Essai";
  string h;

  cout << "L'entier a vaut " << a << endl;
  cin >> a;
  cout << "Maintenant, il vaut " << a << endl;
  cout << "Le grand entier b vaut " << b << endl;
  cin >> b;
  cout << "Maintenant, il vaut " << b << endl;
  cout << "Le booléen c vaut " << c << endl;
  cin >> c;
  cout << "Maintenant, il vaut " << c << endl;
  cout << "Le réel d vaut " << d << endl;
  cin >> d;
  cout << "Maintenant, il vaut " << d << endl;
  cout << "Le réel double précision e vaut " << e << endl;
  cin >> e;
  cout << "Maintenant, il vaut " << e << endl;
  cout << "Le caractère f vaut " << f << endl;
  cin >> f;
  cout << "Maintenant, il vaut " << f << endl;
  cout << "La chaîne g contient " << g << endl;
  cin >> h;
  cout << "Maintenant le string h contient " << h << endl;

  complex<double> x(1.2, 3.4);
  cout << "Le complexe x vautt " << x << endl;
  x *= x;
  cout << "Maintenant il vaut " << x << endl;

}
