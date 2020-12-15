#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int hamming_distance(int x, int y) {
  vector<int> x_bits, y_bits;
  while (x > 0) {
    x_bits.push_back(x % 2);
    x /= 2;
  }

  while (y > 0) {
    y_bits.push_back(y % 2);
    y /= 2;
  }

  const auto max_size = max(x_bits.size(), y_bits.size());
  x_bits.resize(max_size);
  y_bits.resize(max_size);

  auto res = 0;
  for (auto i = 0u; i < x_bits.size(); ++i) {
    if (x_bits[i] != y_bits[i]) {
      ++res;
    }
  }

  return res;
}

int main() {
  cout << "hamming distance is: " << hamming_distance(1, 4) << endl;
  return 0;
}
