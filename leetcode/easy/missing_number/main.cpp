#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int missing_number(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  if (nums.front() != 0) {
    return 0;
  }
  if (nums.back() != static_cast<int>(nums.size())) {
    return nums.size();
  }

  for (auto i = 1u; i < nums.size(); ++i) {
    const auto expected_val = nums[i - 1] + 1;
    if (nums[i] != expected_val) {
      return expected_val;
    }
  }

  return -1;
}

// another approach
int missing_number2(vector<int> &nums) {
  set<int> nums_set(nums.begin(), nums.end());

  for (auto i = 0u; i < nums.size() + 1; ++i) {
    if (!nums_set.count(i)) {
      return i;
    }
  }
  return -1;
}

// approach with gauss sum
int missing_number3(vector<int> &nums) {
  const auto expected_sum = nums.size() * (nums.size() + 1) / 2;
  const auto real_sum = accumulate(nums.begin(), nums.end(), 0);
  return expected_sum - real_sum;
}

int main() {
  vector<int> nums = {3, 0, 1};

  cout << "missing number is: " << missing_number3(nums) << endl;
  return 0;
}
