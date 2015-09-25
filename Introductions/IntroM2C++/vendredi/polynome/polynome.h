#include <iostream>
#include <vector>
using namespace std;

template <class T> class polynome;
template <class T> polynome<T> operator+ (const polynome<T>&, const polynome<T>&);
template <class T> polynome<T> operator- (const polynome<T>&, const polynome<T>&);
template <class T> polynome<T> operator* (const polynome<T>&, const polynome<T>&);
template <class T> ostream& operator<< (ostream& , const polynome<T> &);

template <class T> class polynome {
  vector <T> coeff;
  const static char var = 'x';
  void ajuste(); // pas de 0 en fin de coeff;
 public:
  polynome (T = 0, int = 0); // le monome a.var^n
  polynome (int, const T *);
  bool nul () const {return coeff.size() == 0;}
  int degre () const {return coeff.size() - 1;}
  T& coefficient (int i) {return coeff[i];}
  T coefficient (int i) const {return coeff[i];}
  friend polynome<T> operator+<> (const polynome<T>&, const polynome<T>&);
  friend polynome<T> operator-<> (const polynome<T>&, const polynome<T>&);
  friend polynome<T> operator*<> (const polynome<T>&, const polynome<T>&);
  polynome<T> derivee() const;
  template <class U> U operator() (const U &) const;
  /*
  T operator()  (const T&) const; // valeur en un point
  polynome<T> operator() (const polynome<T>&) const; // composition
  */
  friend ostream& operator<<<> (ostream& , const polynome<T> &);
};

#include "polynome.cpp"
