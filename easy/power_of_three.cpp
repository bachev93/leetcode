#include <iostream>

using namespace std;

bool is_power_of_three(int n) {
  if (n <= 0) {
    return false;
  }

  while (n % 3 == 0) {
    n /= 3;
  }
  return n == 1;
}

int main() {
  cout << boolalpha << is_power_of_three(1) << endl;

  return 0;
}
