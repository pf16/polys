template <class T> T puissance (const T & x, int n)
{
  if (n == 0)
    return 1;
  T y = puissance (x, n / 2);
  return n%2 ? x*y*y : y*y;
}

