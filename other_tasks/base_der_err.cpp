#include <iostream>

using namespace std;

class Base {
public:
  Base(int a) : a(a) {}
  ~Base() {}
  void print() { cout << a; }

  int a;
};

class Derived : public Base {
public:
  Derived(int a) : Base(a) {}
  ~Derived();
};

int main() {
  Base *base = new Derived(10);
  base->print();
  delete base;
  return 0;
}
