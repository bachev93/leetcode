#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_anagram(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, int> s_map, t_map;
  for (auto i = 0u; i < s.size(); ++i) {
    ++s_map[s[i]];
    ++t_map[t[i]];
  }

  return s_map == t_map;
}

// another approach
bool is_anagram2(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  return s == t;
}

// approach with one hash table
bool is_anagram3(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, int> char_ctr;
  for (auto i = 0u; i < s.size(); ++i) {
    ++char_ctr[s[i]];
    --char_ctr[t[i]];
  }

  for (const auto& [_, value] : char_ctr) {
    if (value != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string s("anagram");
  string t("nagaram");

  cout << boolalpha << is_anagram(s, t) << endl;

  return 0;
}
