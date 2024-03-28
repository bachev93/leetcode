#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// approach using std algorithms
int search(vector<int> &nums, int target) {
  auto it = lower_bound(nums.begin(), nums.end(), target);
  if (it == nums.end() || *it != target) {
    return -1;
  }

  return it - nums.begin();
}

int search2(vector<int> &nums, int target) {
  int ind, left = 0, right = nums.size() - 1;
  while (left <= right) {
    ind = left + (right - left) / 2;
    if (nums[ind] == target) {
      return ind;
    }

    if (target < nums[ind]) {
      right = ind - 1;
    } else {
      left = ind + 1;
    }
  }

  return -1;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << "binary_search pos: " << search(nums, 4);

  return 0;
}
