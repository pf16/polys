#include <iostream>
#include <iomanip>
#include <fstream>

// #define __USE_STATIC__

using namespace std;

class matrice {
  int dim;
  double *coeffs;
public:
  matrice (int n = 2, double *v = 0);
  matrice (int, double (int, int));
  matrice (const matrice&);
  matrice (istream & s);
  ~matrice ();
  
  int dimension() const {return dim;}
  matrice& operator= (const matrice& m);
  double& operator () (int l, int c) {return coeffs[dim * l + c];}
  const double& operator () (int l, int c) const {return coeffs[dim * l + c];}
  matrice& operator+= (const matrice& m);
  matrice operator+ (const matrice&) const;
  matrice operator* (const matrice&) const;

#ifdef __USE_STATIC__
  static matrice identite (int n)
  {
    cerr << "static\n";
    return matrice (n, [] (int l, int c) {return (double) (l == c);});
  }
#endif

  friend ostream& operator<< (ostream& s, const matrice& m);
};

matrice::matrice (int n, double * v) : dim(n), coeffs(new double[n*n])
{
  if (v)
    {for (int i = 0; i< n*n; ++i) coeffs[i] = v[i];}
  else
    {for (int i = 0; i < n*n; ++i) coeffs[i] = 0;}
}

matrice::matrice (int n, double f(int, int)) : dim(n), coeffs(new double[n*n])
{
  for (int l = 0; l < dim; ++l)
    for (int c = 0; c < dim; ++c)
      (*this)(l, c) = f(l, c);
}

matrice::matrice (const matrice& m) : dim(m.dim), coeffs (new double[m.dim * m.dim])
{
  for (int i = 0; i < dim * dim; ++i)
    coeffs[i] = m.coeffs[i];
}

matrice::matrice (istream & s)
{
  s >> dim;
  coeffs = new double [dim * dim];
  for (int l = 0; l < dim; ++l)
    for (int c = 0; c < dim; ++c)
      s >> (*this)(l, c);
}

matrice::~matrice () {delete[] coeffs;}

matrice& matrice::operator= (const matrice & m)
{
  if (coeffs != m.coeffs)
    {
      delete[] coeffs;
      dim = m.dim;
      coeffs = new double [dim * dim];
      for (int i = 0; i < dim * dim; ++i)
	coeffs[i] = m.coeffs[i];
    }
  return *this;
}

matrice& matrice::operator += (const matrice& m)
{
  for (int i = 0; i < dim * dim; ++i)
    coeffs[i] += m.coeffs[i];
  return *this;
}

matrice matrice::operator+ (const matrice &m) const
{
  matrice res(*this);
  return res += m;
}

matrice matrice::operator* (const matrice &m) const
{
  matrice res(dim);
  for (int l = 0; l < dim; ++l)
    for (int c = 0; c < dim; ++c)
      for (int i = 0; i < dim; ++i)
	res(l, c) += (*this)(l, i) * m(i, c);
  return res;
}

ostream& operator<< (ostream& s, const matrice& m)
{
  s << m.dim << endl;
  for (int l = 0; l < m.dim; ++l)
    {
      for (int c = 0; c < m.dim; ++c)
	s << setw(10) << m(l, c);
      s << endl;
    }
  return s;
}

#ifndef __USE_STATIC__
double diagonale (int l, int c)
{
  return l == c;
}

matrice identite (int n)
{
  cerr << "global\n";
  return matrice (n, diagonale);
}
#endif

matrice puissance (const matrice& m, int n)
{
  if (n < 2)
#ifdef __USE_STATIC__
    return (n == 1) ? m : matrice::identite (m.dimension());
#else
    return (n == 1) ? m : identite (m.dimension());
#endif

  matrice res = puissance (m, n/2);
  res = res * res;
  return (n%2) ? m*res : res;
}
 
int main (int argc, const char *argv[])
{
  if (argc != 4)
    {
      cerr << "Syntaxe: " << argv[0] << " <fichier d'entrée> <puissance> <fichier de sortie>\n";
      abort ();
    }
  ifstream entree (argv[1]);
  matrice mat(entree);
  cout << "Entrée: matrice de dimension " << mat;
  int n = atoi(argv[2]);
  matrice res = puissance (mat, n);
  cout << "à la puissance " << n << ", cela donne: " << res;
  ofstream sortie (argv[3]);
  sortie << res;
}
