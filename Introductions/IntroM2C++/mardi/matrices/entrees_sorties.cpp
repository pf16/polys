#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

typedef double ** matrice;

void lire (istream& s, int& dim, matrice & m)
{
  s >> dim;
  m = new double * [dim];
  for (int l = 0; l < dim; l++)
    {
      m[l] = new double [dim];
      for (int c = 0; c < dim; c++)
	s >> m[l][c];
    }
}

void ecrire (ostream& s, int dim, const matrice m)
{
  s << dim << endl;
  for (int l = 0; l < dim; l++)
    for (int c = 0; c < dim; c++)
      s << m[l][c] << endl;
}

matrice produit (matrice m1, matrice m2, int dim)
{
  matrice m = new double * [dim];
  for (int l = 0; l < dim; l++)
    {
      m[l] = new double [dim];
      for (int c = 0; c < dim; ++c)
	{
	  double s = 0;
	  for (int i = 0; i < dim; ++i)
	    s += m1[l][i] * m2[i][c];
	  m[l][c] = s;
	}
    }
  return m;
}

int main (int argc, const char * argv[])
{
  if (argc != 3)
    {
      cerr << "Syntaxe: " << argv[0] << " <fichier d'entrée> <fichier de sortie>\n";
      abort ();
    }
  ifstream entree (argv[1]);
  matrice mat;
  int dimension;
  lire (entree, dimension, mat);
  matrice carre = produit (mat, mat, dimension);
  ofstream sortie (argv[2]);
  ecrire (sortie, dimension, carre);
}
