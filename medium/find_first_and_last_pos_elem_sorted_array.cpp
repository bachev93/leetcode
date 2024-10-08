#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  const auto position = equal_range(nums.begin(), nums.end(), target);

  if (position.first == nums.end() || *position.first != target) {
    return {-1, -1};
  }

  const int left = static_cast<int>(distance(nums.begin(), position.first));
  const int right =
      static_cast<int>(distance(nums.begin(), position.second)) - 1;
  return {left, right};
}

int main() {
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  const int target = 8;

  const vector<int> result = searchRange(nums, target);

  for (auto elem : result) {
    cout << elem << ", ";
  }
  cout << endl;
}
