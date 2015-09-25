#include "graphe.h"
#include <fstream>

ostream& operator<< (ostream& s, const graphe& G)
{
  s << G.ns << " sommets, " << G.na << " arcs." << endl;
  for (int i = 0; i < G.ns; i++)
    for (list<arc>::iterator p = G.arcs[i].begin (); p != G.arcs[i].end (); p++)
      s << *p << endl;
  return s;
}

graphe::graphe (int sommets, int aretes, long seed) : ns (sommets), na(0)
{
  srand(seed); rand();
  arcs = new list<arc> [ns];
  for (int i = 0; i < aretes; i++)
    addarc (rand() % ns, rand() % ns, rand()/(double)RAND_MAX);
}

graphe::graphe (const char *filename)
{
  ifstream f(filename);
  int naretes;
  f >> ns >> naretes;
  arcs = new list<arc> [ns];
  na = 0;
  for (int i = 0; i < naretes; i++)
    {
      int a, b; double c;
      f >> a >> b >> c;
      addarc (a, b, c);
    }
}
