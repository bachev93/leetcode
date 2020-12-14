#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int hamming_weight(uint32_t n) {
  auto count = 0;
  while (n > 0) {
    count += n % 2;
    n /= 2;
  }

  return count;
}

int main() {
  cout << "hamming weight: " << hamming_weight(3) << endl;

  return 0;
}
