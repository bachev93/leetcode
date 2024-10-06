#include <iostream>

namespace {
const auto bad_v = 7;
bool isBadVersion(int val) { return val >= bad_v; }
} // namespace

int first_bad_version(int n) {
  auto left = 1;
  auto right = n;
  while (left < right) {
    const auto mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

using namespace std;

int main() {
  cout << "1st bad version is: " << first_bad_version(10) << endl;
  return 0;
}
