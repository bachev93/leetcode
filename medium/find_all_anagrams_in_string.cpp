#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// sliding window, BEST
vector<int> findAnagrams(string s, string p) {
  if (p.size() > s.size()) {
    return {};
  }

  vector<int> indices;

  unordered_map<char, int> p_map;
  for (auto elem : p) {
    ++p_map[elem];
  }

  unordered_map<char, int> s_map;
  for (int i = 0; i < p.size(); ++i) {
    ++s_map[s[i]];
  }

  for (int i = 1; i + p.size() <= s.size(); ++i) {
    if (p_map == s_map) {
      indices.push_back(i - 1);
    }

    --s_map[s[i - 1]];
    if (s_map[s[i - 1]] == 0) {
      s_map.erase(s[i - 1]);
    }

    ++s_map[s[i + p.size() - 1]];
  }

  if (p_map == s_map) {
    indices.push_back(s.size() - p.size());
  }

  return indices;
}

// my bruteforce solution
vector<int> findAnagrams2(string s, string p) {
  if (p.size() > s.size()) {
    return {};
  }

  vector<int> indices;
  sort(p.begin(), p.end());
  auto p_len = p.size();
  for (auto it = s.begin(); it != s.end() - (p_len - 1); ++it) {
    string sub_string(it, it + p.size());
    sort(sub_string.begin(), sub_string.end());
    if (p == sub_string) {
      indices.push_back(it - s.begin());
    }
  }

  return indices;
}

// bruteforce 2
vector<int> findAnagrams3(string s, string p) {
  if (p.size() > s.size()) {
    return {};
  }

  vector<int> indices;

  unordered_map<char, int> p_map;
  for (auto elem : p) {
    ++p_map[elem];
  }

  const auto p_len = p.size();
  for (int i = 0; i + p_len <= s.size(); ++i) {
    unordered_map<char, int> substr_map;
    for (int j = i; j < i + p_len; ++j) {
      ++substr_map[s[j]];
    }

    if (substr_map == p_map) {
      indices.push_back(i);
    }
  }

  return indices;
}

int main() {
  string s{"cbaebabacd"};
  string p{"cba"};

  //   string s{"aaaaaaaaaa"};
  //   string p{"aaaaaaaaaaaaa"};
  auto indices = findAnagrams(s, p);

  cout << "[ ";
  for (const auto elem : indices) {
    cout << elem << ", ";
  }
  cout << "]" << endl;

  return 0;
}
