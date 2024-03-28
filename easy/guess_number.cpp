#include <iostream>

using namespace std;

int guess(int n) { return n; }

// binary search approach
int guessNumber(int n) {
  auto left = 1;
  auto right = n;

  while (left <= right) {
    const auto mid = left + (right - left) / 2;
    auto ans = guess(mid);

    if (ans == 0) {
      return mid;
    } else if (ans < 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

// ternary search approach (worse than binary search)
int guessNumber2(int n) {
  auto left = 1;
  auto right = n;

  while (left <= right) {
    const auto mid1 = left + (right - left) / 3;
    const auto mid2 = right - (right - left) / 3;
    auto ans1 = guess(mid1);
    auto ans2 = guess(mid2);
    if (ans1 == 0) {
      return mid1;
    } else if (ans2 == 0) {
      return mid2;
    } else if (ans1 < 0) {
      right = mid1 - 1;
    } else if (ans2 > 0) {
      left = mid2 + 1;
    } else {
      left = mid1 + 1;
      right = mid2 - 1;
    }
  }

  return -1;
}

int main() { return 0; }
