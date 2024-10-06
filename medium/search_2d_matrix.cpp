#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// my BRUTEFORCE solution, BEST
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  bool result = false;
  for (uint row = 0; row < matrix.size(); ++row) {
    auto it = lower_bound(matrix[row].begin(), matrix[row].end(), target);
    if (it != matrix[row].end() && *it == target) {
      result = true;
      break;
    }
  }

  return result;
}

// solution from leetcode. Consider 2D matrix as 1D array
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
  const int rows = matrix.size();
  const int cols = matrix[0].size();

  int start = 0;
  int end = rows * cols - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    int row = mid / cols;
    int col = mid % cols;

    if (target == matrix[row][col]) {
      return true;
    } else if (target > matrix[row][col]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }

  return false;
}

int main() {
  cout << "search 2D matrix: " << endl;

  vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  const int target{3};

  vector<vector<int>> matrix2{{1, 1}};
  const int target2{2};

  cout << "result = " << searchMatrix2(matrix, target) << endl;

  return 0;
}