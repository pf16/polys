#include <iostream>
#include <iomanip>
using namespace std;

struct noeud {
  int valeur;
  noeud *suite;
};

int main ()
{
  noeud *tete = 0;
  for (int i = 0; i < 10; i++)
    {
      noeud *p = new noeud;
      p->valeur = i;
      p->suite = tete;
      tete = p;
    }
  while (tete)
    {
      noeud *p = tete;
      cout << tete->valeur << endl;
      tete = tete->suite;
      delete p;
    }
}
