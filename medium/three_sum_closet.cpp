#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int threeSumClosest(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());

  int result = std::numeric_limits<int>::max() / 2;
  for (int i = 0; i < nums.size() - 2; ++i) {
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[i] + nums[right];
      if (abs(sum - target) < abs(result - target)) {
        result = sum;
      }

      if (sum < target) {
        ++left;
      } else if (sum > target) {
        --right;
      } else {
        return sum;
      }
    }
  }

  return result;
}

int main() {
  // int target = 1;
  // vector<int> nums = {-1,2,1,-4};

  // int target = -100;
  // vector<int> nums = {1, 1, 1, 1};

  int target = -2;
  vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};

  auto result = threeSumClosest(nums, target);
  cout << "result = " << result << endl;
}