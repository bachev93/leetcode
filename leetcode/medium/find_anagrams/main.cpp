#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
  if (s.size() < p.size()) {
    return {};
  }
  vector<int> res;

  unordered_map<char, int> occ;
  for (auto c : p) {
    --occ[c];
  }

  for (auto i = 0u; i < p.size(); ++i) {
    if (++occ[s[i]] == 0) {
      occ.erase(s[i]);
    }
  }

  if (occ.empty()) {
    res.push_back(0);
  }

  for (auto i = p.size(), j = 0ul; i < s.size(); ++i, ++j) {
    if (++occ[s[i]] == 0) {
      occ.erase(s[i]);
    }

    if (--occ[s[j]] == 0) {
      occ.erase(s[j]);
    }

    if (occ.empty()) {
      res.push_back(j + 1);
    }
  }

  return res;
}

int main() {
  string s = "cbaebabacd", p = "abc";
  //  string s = "abab", p = "ab";
  auto res = findAnagrams(s, p);

  for (auto ind : res) {
    cout << ind << ", ";
  }
  cout << endl;

  return 0;
}
