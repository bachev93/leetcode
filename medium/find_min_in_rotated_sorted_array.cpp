#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
  int start = 0;
  int end = nums.size() - 1;

  while (start < end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] > nums[end]) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }

  return nums[end];
}

int main() {
  cout << "find minimum in rotated sorted array:" << endl;

  vector<int> nums{3, 4, 5, 1, 2};
  vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
  vector<int> nums3{11, 13, 15, 17};

  cout << "min = " << findMin(nums) << endl;

  return 0;
}