#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> res(2);
  unordered_map<int, int> cache;
  for (auto i = 0u; i < nums.size(); ++i) {
    const auto needed_num = target - nums[i];
    if (cache.find(needed_num) != cache.end()) {
      res[0] = cache[needed_num];
      res[1] = i;
      return res;
    }
    cache[nums[i]] = i;
  }
  return res;
}

int main() {
  //  vector<int> nums = {2, 7, 11, 15};
  //  auto target = 9;
  vector<int> nums = {3, 2, 4};
  auto target = 6;

  auto res = twoSum(nums, target);
  cout << "[";
  for (const auto& elem : res) {
    cout << elem << ", ";
  }
  cout << "]";

  return 0;
}
