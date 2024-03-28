#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void move_zeroes(vector<int>& nums) {
  const auto it = remove(nums.begin(), nums.end(), 0);
  fill(it, nums.end(), 0);
}

// approach 2
void move_zeroes2(vector<int>& nums) {
  int n = nums.size();

  // Count the zeroes
  int numZeroes = 0;
  for (int i = 0; i < n; i++) {
    numZeroes += (nums[i] == 0);
  }

  // Make all the non-zero elements retain their original order.
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (nums[i] != 0) {
      ans.push_back(nums[i]);
    }
  }

  // Move all zeroes to the end
  while (numZeroes--) {
    ans.push_back(0);
  }

  // Combine the result
  for (int i = 0; i < n; i++) {
    nums[i] = ans[i];
  }
}

// approach 3
void move_zeroes3(vector<int>& nums) {
  int lastNonZeroFoundAt = 0;
  // If the current element is not 0, then we need to
  // append it just in front of last non 0 element we found.
  for (auto i = 0u; i < nums.size(); i++) {
    if (nums[i] != 0) {
      nums[lastNonZeroFoundAt++] = nums[i];
    }
  }
  // After we have finished processing new elements,
  // all the non-zero elements are already at beginning of array.
  // We just need to fill remaining array with 0's.
  for (uint i = lastNonZeroFoundAt; i < nums.size(); i++) {
    nums[i] = 0;
  }
}

int main() {
  vector<int> vals{0, 1, 0, 3, 12};
  move_zeroes(vals);

  for (const auto elem : vals) {
    cout << elem << ", ";
  }
  cout << endl;

  return 0;
}
