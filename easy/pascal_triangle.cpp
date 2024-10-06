#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> res(numRows);
  for (auto i = 0u; i < res.size(); ++i) {
    res[i].resize(i + 1);
    res[i].front() = res[i].back() = 1;
  }

  for (auto i = 0u; i < res.size(); ++i) {
    for (auto j = 0u; j < res[i].size(); ++j) {
      if (!res[i][j]) {
        res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
  }

  return res;
}

int main() {
  const auto num_rows = 5;
  const auto pascal_triangle = generate(num_rows);

  for (const auto& row : pascal_triangle) {
    for (const auto elem : row) {
      cout << elem << ", ";
    }
    cout << endl;
  }

  return 0;
}
