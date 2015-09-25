#include <iomanip>
#include <queue>
#include <cstdlib>
#include "graphe.h"

using namespace std;

bool operator< (const arc& x, const arc& y)
{
  return x.cout > y.cout;
}

arc *antecedents (const graphe& G, int origine)
{
  arc * ante = new arc [G.ns];
  for (int i = 0; i < G.ns; i++)
    ante[i] = 0;
  priority_queue <arc> my_queue;
  my_queue.push (arc(-1, origine, 0));
  while (!my_queue.empty ())
    {
      arc a = my_queue.top ();
      my_queue.pop ();
      if (!ante[a.fin])
	{
	  int s = a.fin;
	  ante [s] = arc(a);
	  for (list<arc>::iterator p = G.arcs[s].begin (); p != G.arcs[s].end (); p++)
	    my_queue.push (arc(p->debut, p->fin, p->cout + a.cout));
	}
    }
  return ante;
}

void aux (arc *p, int a, int b)
{
  if (b != a)
    {
      aux (p, a, p[b].debut);
      cout << " -> ";
    }
  cout << b;
}

void affiche_chemin (const graphe& G, int origine, int fin)
{
  arc *res = antecedents (G, origine);
  if (res [fin])
    {
      aux (res, origine, fin);
      cout << endl << "Coût: " << setprecision(15) << res[fin].cout << endl;
    }
  else
    cout << "Pas de chemin possible." << endl;
}

int main (int argc, const char *argv[])
{
  graphe *g = (argc == 2) ?
    new graphe (argv[1]) :
    new graphe (atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

  if (g->na <= 1000)
    cout << *g << endl;
  affiche_chemin (*g, 2, 3);

  return 0;
} 
