#include <iostream>

using namespace std;

template <int S> class Clazz {
public:
  enum { N = 2 + Clazz<S - 1>::N + Clazz<S - 2>::N };
};

template <> class Clazz<1> {
public:
  enum { N = 3 };
};

template <> class Clazz<2> {
public:
  enum { N = 2 };
};

int main() {
  cout << Clazz<3>::N << endl;
  return 0;
}
