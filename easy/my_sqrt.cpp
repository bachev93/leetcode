#include <cmath>
#include <iostream>

using namespace std;

int my_sqrt(int x) {
  const auto res = sqrt(x);
  return static_cast<int>(res);
}

int main() {
  cout << my_sqrt(8) << endl;
  return 0;
}
