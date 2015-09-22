 #include <iostream>
#include <iomanip>
using namespace std;

int dimension;
bool *col;
bool *diag1, *diag2;
long solutions;

void explore (int ligne)
{
  if (ligne == dimension)
    solutions++;
  else
    for (int i = 0; i < dimension; ++i)
      if (col[i] && diag1[i-ligne] && diag2[i+ligne])
	{
	  col[i] = diag1[i-ligne] = diag2[i+ligne] = false;
	  explore (ligne + 1);
	  col[i] = diag1[i-ligne] = diag2[i+ligne] = true;
	}
}

int main (int argc, const char** argv)
{
  if (argc != 2)
    {
      cerr << "Syntaxe: " << argv[0] << " <dimension maximum>\n";
      abort ();
    }
  int dim_max = atoi (argv[1]);
  for (dimension = 1; dimension <= dim_max; ++dimension)
    {
      col = new bool [5 * dimension];
      diag1 = col + 2 * dimension;
      diag2 = diag1 + dimension;
      for (int i = 0; i < 5 * dimension; i++)
	col [i] = true;
      solutions = 0;
      explore (0);
      cout << "Pour un échiquier de dimension " << setw(2) << dimension
	   << ", il y a " << setw(8) << solutions << " solutions.\n";
      delete [] col;
    }
  return 0;
}
