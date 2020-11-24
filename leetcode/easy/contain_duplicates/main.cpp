#include <algorithm>
#include <ios>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool contains_duplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  const auto it = unique(nums.begin(), nums.end());
  return (it == nums.end() ? false : true);
}

// another approach
bool contains_duplicate2(vector<int>& nums) {
  unordered_set<int> set_nums(nums.begin(), nums.end());
  return nums.size() > set_nums.size();
}

// simple approach
bool contains_duplicate3(vector<int>& nums) {
  for (auto i = 0u; i < nums.size(); ++i) {
    for (auto j = 0u; j < i; ++j) {
      if (nums[j] == nums[i]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  vector<int> nums = {1, 2, 3, 1};
  cout << boolalpha << contains_duplicate2(nums) << endl;
  //  cout << boolalpha << contains_duplicate(nums) << endl;
  //  cout << boolalpha << contains_duplicate3(nums) << endl;

  return 0;
}
