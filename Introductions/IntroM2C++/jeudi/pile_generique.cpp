#include <iostream>
using namespace std;

template <class T> class pile {
  struct noeud {
    T valeur;
    struct noeud *suite;
    noeud (const T & t, noeud *p) : valeur (t), suite (p) {}
  } *tete;
public:
  pile <T> () {tete = 0;}
  void pousse (const T & x) {tete = new noeud (x, tete);}
  bool vide () const {return tete == 0;}
  T & sommet () const {return tete->valeur;}
  T tire ();
  ~pile<T> () {while (!vide()) tire ();}
};

template <class X> X pile<X>::tire()
{
  X res = sommet();
  noeud *p = tete->suite;
  delete tete;
  tete = p;
  return res;
}

int main ()
{
  pile <double> l;
  for (int i = 0; i < 10; i++)
    l.pousse (i/10.);
  while (!l.vide())
      cout << l.tire() << endl;
}
