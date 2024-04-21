#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> merged_intervals;

  sort(intervals.begin(), intervals.end());
  for(auto&& interval : intervals) {
    // if the list of merged intervals is empty or if the current interval does not overlap with the previous, simply append it.
    if(merged_intervals.empty() ||
      merged_intervals.back()[1] < interval[0]) {
      merged_intervals.push_back(std::move(interval));
    } else {
      // otherwise, there is overlap, so we merge the current and previous intervals.
      merged_intervals.back()[1] = max(merged_intervals.back()[1], interval[1]);
    }
  }

  return merged_intervals;
}

int main() {
  cout << "merge intervals: " << endl;

  // expect: [[1,6],[8,10],[15,18]]
  vector<vector<int>> intervals{{1, 3},
                                {2, 6},
                                {8, 10},
                                {15, 18}};
  
  vector<vector<int>> intervals2{{1, 9},
                                 {2, 5},
                                 {19, 20},
                                 {10, 11},
                                 {12, 20},
                                 {0, 3},
                                 {0, 1},
                                 {0, 2}};

  // expect [[1,5]]
  vector<vector<int>> intervals3 {{1, 4}, {4, 5}};

  const auto result = merge(intervals);

  cout << "{";
  for(const auto& interval : result) {
    cout << "{";
    for(const auto elem : interval) {
      cout << elem << ", ";
    }
    cout << "}, " ;
  }
  cout << "}" << endl;


  return 0;
}
