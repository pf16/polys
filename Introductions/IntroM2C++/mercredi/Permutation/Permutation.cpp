#include <assert.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "Permutation.h"

Permutation::Permutation (int a) : n(a), v(new int[a])
{
  for (int i = 0; i < n; i++)
    v[i] = i;
}

Permutation::Permutation (const Permutation& s) : n(s.n),  v(new int [s.n])
{
  for (int i = 0; i < n; i++)
    v[i] = s.v[i];
}

Permutation& Permutation::operator= (const Permutation& s)
{
  n = s.n;
  int *w = new int [n];
  for (int i = 0; i < n; i++)
    w[i] = s.v[i];
  delete [] v;
  v = w;
  return *this;
}

Permutation operator* (const Permutation& s1, const Permutation&s2)
{
  assert (s1.n == s2.n);
  Permutation t(s1.n);
  for (int i = 0; i < s1.n; i++)
    t.v[i] = s1.v[s2.v[i]];
  return t;
}

Permutation Permutation::inverse()
{
  Permutation t(n);
  for (int i = 0; i < n; i++)
    t.v[v[i]] = i;
  return t;
}

bool Permutation::next()
{
  int k, l;
  for (k = n - 2; k >= 0; k--)
    if (v[k + 1] > v[k])
      break;
  if (k < 0)
    return false;
  int m = v[k];
  for (l = n - 1; v[l] < m; l--);
  v[k] = v[l]; v[l] = m;
  for (k++, l = n -1; k < l; k++, l--)
    {
      m = v[k]; v[k] = v[l]; v[l] = m;
    }
  return true;
}

ostream& operator<< (ostream& s, const Permutation& p)
{
  s << '(';
  for (int i = 0; i < p.n; i++)
    {
      if (i)
	s << ' ';
      s << p.v[i] + 1;
    }
  return s << ')';
}

void Permutation::rand()
{
  for (int i = 0; i < n; i++)
    {
      int a = abs(::rand() / 2) % (i + 1);
      v[i] = v[a];
      v[a] = i;
     }
}

void Permutation::printCycles (ostream &s) const
{
  bool *a = new bool[n];
  for (int i = 0; i < n; i++)
    a[i] = true;
  for (int j = 0; j < n; j++)
    if (a[j] && (v[j] != j))
      {
	s << '(' << j + 1;
	for (int c = v[j]; c != j; c = v[c])
	  {
	    s << ',' << c + 1;
	    a[c] = false;
	  }
	s << ')';
      }
  delete [] a;
}

int Permutation::signature () const
{
  bool *a = new bool[n];
  int s = 1;
  for (int i = 0; i < n; i++)
    a[i] = true;
  for (int j = 0; j < n; j++)
    if (a[j] && (v[j] != j))
      for (int c = v[j]; c != j; c = v[c])
	{
	  s *= -1;
	  a[c] = false;
	}
  delete [] a;
  return s;
}

static int pgcd (int a, int b)
{
  if (a == 0)
    return b;
  return pgcd (b % a, a);
}

static int ppcm (int a, int b)
{
  return a * (b / pgcd (a, b));
}

int Permutation::ordre () const
{
  bool *a = new bool[n];
  int s = 1;
  for (int i = 0; i < n; i++)
    a[i] = true;
  for (int j = 0; j < n; j++)
    if (a[j] && (v[j] != j))
      {
	int l = 1;
	for (int c = v[j]; c != j; c = v[c])
	  {
	    l++;
	    a[c] = false;
	  }
	s = ppcm (s, l);
      }
  delete [] a;
  return s;
}

/*
bool Permutation::operator==(const Permutation & s) const
{
  if (s.n != n)
    return false;
  for (int i = 0; i < n; ++i)
    if (s.v[i] != v[i])
      return false;
  return true;
}
*/

bool operator==(const Permutation & s, const Permutation & t)
{
  if (s.n != t.n)
    return false;
  for (int i = 0; i < s.n; ++i)
    if (s.v[i] != t.v[i])
      return false;
  return true;
}
