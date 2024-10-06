#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int max_area{0};
  const int height_len = height.size();
  int left = 0;
  int right = height_len - 1;

  while (left < right) {
    max_area = max(max_area, min(height[left], height[right]) * (right - left));

    if (height[left] < height[right]) {
      ++left;
    } else {
      --right;
    }
  }

  return max_area;
}

int main() {
  cout << "container with must water: " << endl;

  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height2{1, 1};

  cout << "result = " << maxArea(height) << endl;

  return 0;
}
