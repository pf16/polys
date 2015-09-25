#include <iostream>
using namespace std;

template <int n> struct modulo {
  int a;
  modulo<n> (int m = 0) :a(m%n){}
  modulo<n> operator+ (modulo<n> b) const {return modulo<n> (a+b.a);}
  modulo<n> operator- (modulo<n> b) const {return modulo<n> (n+a-b.a);}
  modulo<n> operator* (modulo<n> b) const {return modulo<n> (a*b.a);}
  friend ostream& operator<< (ostream& s, const modulo<n>& x) {return s << x.a << " (mod " << n << ")";}
};

