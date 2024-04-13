#include <vector>
#include <iostream>

using namespace std;


// leetcode solution
int search(vector<int>& nums, int target) {
  int start = 0;
  int end = nums.size() - 1;
  int mid = 0;

  while(start <= end) {
    mid = start + (end - start) / 2;

    if(target == nums[mid]) {
      return mid;
    }

    if(nums[start] <= nums[mid]) {
      if(target >= nums[start] && target < nums[mid]) {
        end = mid -1;
      } else {
        start = mid + 1;
      }
    } else {
      if(target > nums[mid] && target <= nums[end]) {
        start = mid +1;
      } else {
        end = mid - 1;
      }
    }
  }

  return -1;
}

int main() {
  cout << "search in rotated sorted array: " << endl;

  vector<int> nums{4,5,6,7,0,1,2};
  int target{0};

  vector<int> nums2{4,5,6,7,0,1,2};
  int target2{3};

  vector<int> nums3{1};
  int target3{0};

  cout << search(nums, target) << endl;

  return 0;
}