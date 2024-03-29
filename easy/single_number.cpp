#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int single_number(vector<int>& nums) {
  unordered_map<int, int> vals;
  for (const auto elem : nums) {
    ++vals[elem];
  }

  for (const auto& [key, value] : vals) {
    if (value == 1) {
      return key;
    }
  }
  return 0;
}

// another approach, O(1) in memory. BEST!
int single_number2(vector<int>& nums) {
  auto res = 0;
  for (const auto elem : nums) {
    res ^= elem;
  }
  return res;
}

// another approach. OK
int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i+=2) {
        if(nums[i] != nums[i -1]) {
            return nums[i-1];
        }
    }
    return nums[nums.size() - 1];
}

int main() {
  vector<int> nums = {2, 2, 1};
  //  cout << single_number(nums) << endl;
  cout << single_number2(nums) << endl;
  return 0;
}
