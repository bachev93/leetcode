#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  auto it = remove_if(nums.begin(), nums.end(),
                      [&val](int elem) { return elem == val; });
  nums.erase(it, nums.end());
  return nums.size();
}

int main() {
  vector<int> nums = {3, 2, 2, 3};
  const int val = 3;

  const int result = removeElement(nums, val);
  cout << "result = " << result << endl;
}
