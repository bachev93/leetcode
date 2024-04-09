#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// solution from leetcode, BEST
vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> nums_count;
  for(auto num : nums) {
    ++nums_count[num];
  }

  vector<pair<int, int>> freq_elements(make_move_iterator(nums_count.begin()),
                                       make_move_iterator(nums_count.end()));

  sort(freq_elements.begin(), freq_elements.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.second > rhs.second;
  });

  vector<int> result;
  for(int i = 0; i < k; ++i) {
    result.push_back(freq_elements[i].first);
  }

  return result;
}

// my BRUTEFORCE solution
vector<int> topKFrequent2(vector<int>& nums, int k) {
  unordered_map<int, int> nums_count;
  for(auto num : nums) {
    ++nums_count[num];
  }

  vector<pair<int, int>> freq_elements;
  for(const auto& [num, counter] : nums_count) {
    freq_elements.push_back({counter, num});
  }

  sort(freq_elements.begin(), freq_elements.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.first > rhs.first;
  });

  vector<int> result;
  for(int i = 0; i < k; ++i) {
    result.push_back(freq_elements[i].second);
  }

  return result;
}

int main() {
  vector<int> nums{1,1,1,2,2,3};
  int k = 2;

  vector<int> nums2{1};
  int k2 = 1;

  cout << "top k frequent elements: ";
  for(auto elem : topKFrequent(nums, k)) {
    cout << elem << ", ";
  }
  cout << endl;
  
  return 0;
}
