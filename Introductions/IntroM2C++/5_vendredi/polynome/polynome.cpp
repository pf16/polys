template <class T>
void polynome<T>::ajuste()
// pas de 0 fin de coeff
{
  int n = coeff.size() - 1;
  while ((n >= 0) && (coeff[n] == 0)) n--;
  coeff.resize (n+1);
}

template <class T>
polynome<T>::polynome (const T a, int n)
// le monome a.var^n
{
  if (a) {coeff.resize(n + 1, 0); coeff[n] = a;}
}

template <class T>
polynome<T>::polynome (int n, const T * v) : coeff(n)
{
  for (int i = 0; i < n; ++i) coeff[i] = v[i];
  ajuste ();
}

template <class T>
polynome<T> operator+ (const polynome<T>& p1, const polynome<T>& p2)
{
  polynome<T> res;
  for (int i = 0; i < min (p1.coeff.size(), p2.coeff.size()); i++)
    res.coeff.push_back (p1.coeff[i] + p2.coeff[i]);
  for (int i = p1.coeff.size (); i < p2.coeff.size (); i++)
    res.coeff.push_back (p2.coeff[i]);
  for (int i = p2.coeff.size (); i < p1.coeff.size (); i++)
    res.coeff.push_back (p1.coeff[i]);
  res.ajuste ();
  return res;
}

template <class T>
polynome<T> operator- (const polynome<T>& p1, const polynome<T>& p2)
{
  polynome<T> res;
  for (int i = 0; i < min (p1.coeff.size(), p2.coeff.size()); i++)
    res.coeff.push_back (p1.coeff[i] - p2.coeff[i]);
  for (int i = p1.coeff.size (); i < p2.coeff.size (); i++)
    res.coeff.push_back (-p2.coeff[i]);
  for (int i = p2.coeff.size (); i < p1.coeff.size (); i++)
    res.coeff.push_back (p1.coeff[i]);
  res.ajuste ();
  return res;
}

template <class T>
polynome<T> operator* (const polynome<T>& p1, const polynome<T>& p2)
{
  if (p1.coeff.size () && p2.coeff.size ())
    {
      polynome<T> res (1, p1.coeff.size () + p2.coeff.size () - 2);
      res.coeff[p1.coeff.size () + p2.coeff.size () - 2] = 0;
      for (int i = 0; i < p1.coeff.size (); i++)
	for (int j = 0; j < p2.coeff.size (); j++)
	  res.coeff[i + j] += (p1.coeff[i] * p2.coeff[j]);
      res.ajuste ();
      return res;
    }
  return polynome<T>(T(0));
}

template <class T>
polynome<T> polynome<T>::derivee() const
{
  polynome<T> res;
  for (int i = 1; i < coeff.size (); i++)
    res.coeff.push_back (i * coeff[i]);
  res.ajuste ();
  return res;
}

template <class T>
  template <class U>
U polynome<T>::operator() (const U& x) const
{
  U s = U(0);
  for (int i = degre(); i >= 0; i--)
    {s = x * s; s = s + U(coeff [i]);}
  return s;
}

template <class T>
void monome (ostream& s, const T& a, int n, char var)
{
  if (n)
    {
      if (a != 1)
	s << a;
      s << var;
    }
  else
    s << a;
  if (n > 1)
    s << '^' << n;
}

template <class T>
ostream& operator<< (ostream& s , const polynome<T> & p)
{
  if (p.nul())
    return s << 0;
  int i = p.degre();
  monome (s, p.coefficient(i), i, p.var);
  while (--i >= 0)
    {
      T a = p.coefficient(i);
      if (a) {s << ' '; if (a>0) s << "+ "; monome (s, a, i, p.var);}
    }
  return s;
}
