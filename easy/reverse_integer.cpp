#include <climits>
#include <iostream>

using namespace std;

int reverse(int x) {
  auto rev = 0;
  while (x != 0) {
    auto pop = x % 10;
    x /= 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
      return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
      return 0;
    rev = rev * 10 + pop;
  }
  return rev;
}

int main() {
  while (cin) {
    cout << "enter integer value: ";
    int x;
    cin >> x;

    const auto rev_x = reverse(x);
    cout << "reversed value: " << rev_x << endl;
  }

  return 0;
}
