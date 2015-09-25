#include <iostream>

template <int N>
struct F {static const long valeur = N * F<N-1>::valeur;};

template <>
struct F<0> {static const long valeur = 1;};

int main()
{
  std::cout << F<10>::valeur << std::endl;
}
