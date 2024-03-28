#include <iostream>

using namespace std;

class Base {
 public:
  Base() { throw 0; }
};

class Derived : public Base {
 public:
  Derived() try : Base() {
  } catch (...) {
    cout << "1";
  }
};

int main() {
  try {
    Derived derived;
  } catch (int) {
    cout << "2";
  }

  return 0;
}
