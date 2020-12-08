#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int majority_element(vector<int>& nums) {
  unordered_map<int, size_t> val_cnt;
  for (const auto elem : nums) {
    ++val_cnt[elem];
  }

  pair<int, size_t> res;
  for (const auto& item : val_cnt) {
    if (item.second > nums.size() / 2) {
      res = item;
    }
  }

  return res.first;
}

// another approach
int majority_element2(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() / 2];
}

// TODO: add Boyer-Moore algorithm here

int main() {
  //  vector<int> vals{2, 2, 1, 1, 1, 2, 2};
  vector<int> vals{3, 2, 3};

  const auto res = majority_element(vals);
  cout << "majority element: " << res << endl;
  return 0;
}
