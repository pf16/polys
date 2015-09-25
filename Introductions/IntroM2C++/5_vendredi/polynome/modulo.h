#include <iostream>
using namespace std;

template <int n> struct modulo {
  int a;
  modulo<n> (int m = 0) : a(m % n) {if (a < 0) a += n;}
  modulo<n>& operator= (modulo<n> b) {a = b.a; return *this;}
  modulo<n> operator+ (modulo<n> b) const {return modulo<n> (a+b.a);}
  modulo<n> operator- (modulo<n> b) const {return modulo<n> (n+a-b.a);}
  modulo<n> operator* (modulo<n> b) const {return modulo<n> (a*b.a);}
  modulo<n>& operator+= (modulo<n> b) {return *this = (*this) + b;}
  bool operator> (int m) const {return a != 0;}
  bool operator!= (int m) const {return (a + n - m) % n;}
  operator bool() const {return a;}
  friend ostream& operator<< (ostream& s, modulo<n> x) {return s << x.a;}
};

