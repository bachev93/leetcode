#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int> &nums) {
  auto it = unique(nums.begin(), nums.end());
  nums.erase(it, nums.end());
  return nums.size();
}

int main() {
  //  vector<int> vals = {1, 1, 1, 2, 2, 3, 4, 4, 4};
  vector<int> vals;
  const auto result = remove_duplicates(vals);
  cout << "result: " << result << endl;
  return 0;
}
