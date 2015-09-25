#include <iostream>
#include <vector>

using namespace std;

struct registre {
  static int nombre;
  registre() {++nombre;}
  registre (const registre&) {++nombre;}
  ~registre() {nombre--;}
};

int registre::nombre;

void tally ()
{
  cout << "Nombre d'objets: " << registre::nombre << endl;
}

int main()
{
  tally();
  registre x;
  tally();
  {
    vector<registre> v(5);
    tally();
    v.resize(20);
    tally();
  }
  tally();
}
