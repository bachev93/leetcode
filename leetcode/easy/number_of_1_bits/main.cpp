#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int hamming_weight(uint32_t n) {
  vector<int> bits;
  while (n > 0) {
    bits.push_back(n % 2);
    n /= 2;
  }

  const auto res = count(bits.begin(), bits.end(), 1);
  return res;
}

int main() {
  cout << "hamming weight: " << hamming_weight(5) << endl;
  return 0;
}
