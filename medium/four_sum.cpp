#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  set<vector<int>> result;
  const int nums_size = nums.size();
  sort(nums.begin(), nums.end());

  for(int i = 0; i < nums_size - 3; ++i) {
    for(int j = i + 1; j < nums_size - 2; ++j) {
      const int64_t new_target = static_cast<int64_t>(target) -
                                  static_cast<int64_t>(nums[i]) -
                                  static_cast<int64_t>(nums[j]);
      int low = j + 1;
      int high = nums_size - 1;

      while(low < high) {
        if(nums[low] + nums[high] < new_target) {
          ++low;
        } else if(nums[low] + nums[high] > new_target) {
          --high;
        } else {
          result.insert({nums[i], nums[j], nums[low], nums[high]});
          ++low;
          --high;
        }
      }
    }
  }

  return {make_move_iterator(result.begin()), make_move_iterator(result.end())};
}

// BRUTEFORCE WORST solution, O(n^4)
vector<vector<int>> fourSum2(vector<int>& nums, int target) {
  set<vector<int>> result;
  sort(nums.begin(), nums.end());
  const int nums_size = nums.size();
  for(int i = 0; i < nums_size; ++i) {
    for(int j = i + 1; j < nums_size; ++j) {
      for(int k = j + 1; k < nums_size; ++k) {
        for(int l = k + 1; l < nums_size; ++l) {
          if(target == static_cast<int64_t>(nums[i]) + 
                       static_cast<int64_t>(nums[j]) + 
                       static_cast<int64_t>(nums[k]) + 
                       static_cast<int64_t>(nums[l])) {
            result.insert({nums[i], nums[j], nums[k], nums[l]});
          }
        }
      }
    }
  }

  return {make_move_iterator(result.begin()), make_move_iterator(result.end())};
}

int main() {
  cout << "four sum: " << endl;

  vector<int> nums{1,0,-1,0,-2,2};
  const int target{0};

  vector<int> nums2{2,2,2,2,2};
  const int target2{8};

  // expect {{-5,0,4,5}, {-3,-2,4,5}}
  vector<int> nums3{-5,5,4,-3,0,0,4,-2};
  const int target3{4};

  vector<int> nums4{1000000000, 1000000000, 1000000000, 1000000000};
  const int target4{0};

  const auto result = fourSum(nums, target);

  for(const auto& vec : result) {
    cout << "[ ";
    for(auto elem : vec) {
      cout << elem << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}