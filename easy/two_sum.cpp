#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// brute force
vector<int> twoSum(vector<int>& nums, int target) {
  int n = nums.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {}; // No solution found
}

// BEST
vector<int> twoSum2(vector<int>& nums, int target) {
  unordered_map<int, int> nums_map;
  for (int i = 0; i < nums.size(); ++i) {
    if (int diff = target - nums[i]; nums_map.count(diff)) {
      return {nums_map[diff], i};
    } else {
      nums_map[nums[i]] = i;
    }
  }

  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  auto target = 9;
  // vector<int> nums = {3, 2, 4};
  // auto target = 6;

  auto res = twoSum(nums, target);
  cout << "[";
  for (const auto& elem : res) {
    cout << elem << ", ";
  }
  cout << "]" << endl;

  return 0;
}
