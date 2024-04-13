#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// approach using std algorithms, BEST
int search(vector<int>& nums, int target) {
  auto it = lower_bound(nums.begin(), nums.end(), target);
  if (it != nums.end() && *it == target) {
      return distance(nums.begin(), it);
  }
  return -1;
}

int search2(vector<int> &nums, int target) {
  int start=0;
  int end=nums.size()-1;
  int mid=start+(end-start)/2;

  while(start<=end){
      int number=nums[mid];
      if(number==target){
          return mid;
      }
      if(number<target){
          start=mid+1;
      }
      else{
          end=mid-1;
      }
      mid=start+(end-start)/2;
  }

  return -1;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << "binary_search pos: " << search(nums, 4) << endl;

  return 0;
}
