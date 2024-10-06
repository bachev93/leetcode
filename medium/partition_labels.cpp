#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> partitionLabels(string s) {
  vector<int> res;

  map<char, int> last;
  for (int k = 0; k < s.length(); k++) {
    last[s[k]] = k;
  }

  int j{0};
  int anchor{0};
  for (int i = 0; i < s.size(); ++i) {
    j = max(j, last[s[i]]);
    if (i == j) {
      res.push_back(i - anchor + 1);
      anchor = i + 1;
    }
  }

  return res;
}

int main() {
  cout << "partition labels:" << endl;

  // expect [9,7,8]
  string s{"ababcbacadefegdehijhklij"};

  // expect [10]
  string s2{"eccbbbbdec"};

  const auto result = partitionLabels(s);

  cout << "result = {";
  for (auto elem : result) {
    cout << elem << ", ";
  }
  cout << "}" << endl;

  return 0;
}