#include <iostream>

template <class T>
class A {public: int a;};

template <class T>
class B : public A<T> {
public:
  B() {this->a = 12;}
};


int main ()
{
  B<int>();
}

