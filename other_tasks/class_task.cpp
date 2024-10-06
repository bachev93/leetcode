#include <iostream>

using namespace std;

class A {
public:
  A() { cout << "A"; }
  ~A() { cout << "~A"; }
};

class B : public A {
public:
  B() { cout << "B"; }
  ~B() { cout << "~B"; }
};

class C : public B {
public:
  C() { cout << "C"; }
  ~C() { cout << "~C"; }
};

class D {
public:
  D() : a(), b(), c() {}

private:
  C c;
  B b;
  A a;
};

int main() {
  D* d = new D();
  delete d;
  return 0;
}
