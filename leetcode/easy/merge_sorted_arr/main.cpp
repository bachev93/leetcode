#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int) {
  copy(nums2.begin(), nums2.end(), nums1.begin() + m);
  sort(nums1.begin(), nums1.end());
}

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3, n = 3;
  vector<int> nums2 = {2, 5, 6};
  merge(nums1, m, nums2, n);

  for (const auto elem : nums1) {
    cout << elem << ", ";
  }
  cout << endl;

  return 0;
}
