#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// DFS (depth-first search, алгоритм поиска в глубину) approach
void dfs(vector<vector<char>>& grid, int row, int col) {
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
      grid[row][col] != '1') {
    return;
  }

  grid[row][col] = '0'; // mark as visited
  dfs(grid, row, col + 1);
  dfs(grid, row, col - 1);
  dfs(grid, row + 1, col);
  dfs(grid, row - 1, col);
}

int numIslands(vector<vector<char>>& grid) {
  if (grid.empty() || grid[0].empty()) {
    return 0;
  }

  int result{0};
  for (int row = 0; row < grid.size(); ++row) {
    for (int col = 0; col < grid[0].size(); ++col) {
      if (grid[row][col] == '1') {
        dfs(grid, row, col);
        ++result;
      }
    }
  }

  return result;
}

// BFS (breadth-first search, алгоритм поиска в ширину) approach
int numIslands2(vector<vector<char>>& grid) {
  if (grid.empty() || grid[0].empty()) {
    return 0;
  }

  int result{0};
  queue<pair<int, int>> q;

  const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  const int row_size = grid.size();
  const int column_size = grid[0].size();

  for (int row = 0; row < row_size; ++row) {
    for (int col = 0; col < column_size; ++col) {
      if (grid[row][col] == '1') {
        ++result;

        q.push({row, col});

        while (!q.empty()) {
          const auto [x, y] = q.front();
          q.pop();

          if (x < 0 || x >= row_size || y < 0 || y >= column_size ||
              grid[x][y] != '1') {
            continue;
          }

          grid[x][y] = '0';

          for (const auto& dir : directions) {
            const int nx = x + dir.first;
            const int ny = y + dir.second;
            if (nx >= 0 && nx < row_size && ny >= 0 && ny < column_size &&
                grid[nx][ny] == '1') {
              q.push({nx, ny});
            }
          }
        }
      }
    }
  }

  return result;
}

int main() {
  cout << "number of islands:" << endl;

  // expected = 1
  vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                            {'1', '1', '0', '1', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '0', '0', '0'}};

  // expected = 3
  vector<vector<char>> grid2{{'1', '1', '0', '0', '0'},
                             {'1', '1', '0', '0', '0'},
                             {'0', '0', '1', '0', '0'},
                             {'0', '0', '0', '1', '1'}};

  cout << "result = " << numIslands(grid) << endl;

  return 0;
}
