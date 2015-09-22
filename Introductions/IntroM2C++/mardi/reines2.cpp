#include <iostream>
using namespace std;

int dimension;
bool *col;
bool *diag1, *diag2;
long solutions;
int *sol;

void explore (int ligne)
{
  if (ligne == dimension)
    {
      if (++solutions == 1)
	{
	  for (int l = 0; l < dimension; ++l)
	    {
	      for (int c = 0; c < dimension; ++c)
		cout << ((c == sol[l]) ? '*' : '.');
	      cout << endl;
	    }
	}
    }
  else
    for (int i = 0; i < dimension; ++i)
      if (col[i] && diag1[i-ligne] && diag2[i+ligne])
	{
	  col[i] = diag1[i-ligne] = diag2[i+ligne] = false;
	  sol[ligne] = i;
	  explore (ligne + 1);
	  col[i] = diag1[i-ligne] = diag2[i+ligne] = true;
	}
}

int main (int argc, const char* argv[])
{
  if (argc != 2)
    {
      cerr << "Syntaxe: " << argv[0] << " <dimension>\n";
      abort ();
    }
  int dim_max = atoi (argv[1]);
  sol = new int[dim_max];
  for (dimension = 1; dimension <= dim_max; ++dimension)
    {
      col = new bool [5 * dimension];
      diag1 = col + 2 * dimension;
      diag2 = diag1 + dimension;
      for (int i = 0; i < 5 * dimension; i++)
	col [i] = true;
      solutions = 0;
      explore (0);
      cout << "Pour un échiquier de dimension " << dimension
	   << ", il y a " << solutions << " solutions.\n";
      delete [] col;
    }
  return 0;
}
