#include <iostream>
#include <list>

using namespace std;

struct arc {
  int debut;
  int fin;
  double cout;
  arc (int d = 0, int f = -1, double c = 1) : debut (d), fin (f), cout(c) {}
  operator bool () {return fin >= 0;}
};

inline ostream& operator<< (ostream& s, const arc& x)
{
  return s << x.debut << ' ' << x.fin << ' ' << x.cout;
}

class graphe {
public:
  int ns;
  int na;
  list<arc> *arcs;
  graphe (int sommets, int aretes = 0, long seed = 0);
  graphe (const char *filename);
  void addarc (int d, int f, double p = 1.)
    {arcs[d].push_back (arc (d, f, p)); na++;}
  friend ostream& operator<< (ostream& s, const graphe& G);
  ~graphe () {delete [] arcs;}
};

