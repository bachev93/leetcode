#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// simple approach
void rotate2(vector<int> &nums, int k) {
  k %= nums.size();

  for (auto i = 0; i < k; ++i) {
    auto previous = nums[nums.size() - 1];
    for (auto j = 0u; j < nums.size(); ++j) {
      const auto tmp = nums[j];
      nums[j] = previous;
      previous = tmp;
    }
  }
}

void rotate(vector<int> &nums, int k) {
  k %= nums.size();

  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  auto k = 2 + nums.size();

  rotate(nums, k);

  for (const auto elem : nums) {
    cout << elem << ", ";
  }
  cout << endl;

  return 0;
}
