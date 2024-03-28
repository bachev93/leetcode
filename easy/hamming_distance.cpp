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

// another approach
int hamming_distance2(int x, int y) {
  auto val = x ^ y;
  vector<int> bits;
  while (val > 0) {
    bits.push_back(val % 2);
    val /= 2;
  }

  const auto res = count(bits.begin(), bits.end(), 1);
  return res;
}

// TODO: add here Brian Kernigan's algorithm to count 1s bits in varuable

int main() {
  //  cout << "hamming distance is: " << hamming_distance(1, 4) << endl;
  cout << "hamming distance is: " << hamming_distance2(1, 4) << endl;
  return 0;
}
