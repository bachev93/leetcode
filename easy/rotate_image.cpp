#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using mat = vector<vector<int>>;

void rotate(mat& matrix) {
  // transpose
  for (auto i = 0u; i < matrix.size(); ++i) {
    for (auto j = i; j < matrix.front().size(); ++j) {
      const auto tmp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = tmp;
    }
  }

  for (auto i = 0u; i < matrix.size(); ++i) {
    const auto it_begin = matrix[i].begin();
    const auto it_end = matrix[i].end();
    reverse(it_begin, it_end);
  }
}

int main() {
  //  mat matrix = {
  //      {1, 2, 3},
  //      {4, 5, 6},
  //      {7, 8, 9},
  //  };

  mat matrix = {
      {5, 1, 9, 11},
      {2, 4, 8, 10},
      {13, 3, 6, 7},
      {15, 14, 12, 16},
  };

  cout << "before rotation:" << endl;
  for (const auto& row : matrix) {
    for (const auto& elem : row) {
      cout << elem << "\t";
    }
    cout << endl;
  }

  rotate(matrix);
  cout << "after rotation:" << endl;
  for (const auto& row : matrix) {
    for (const auto& elem : row) {
      cout << elem << "\t";
    }
    cout << endl;
  }

  return 0;
}
