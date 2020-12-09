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

int main() {
  string s("anagram");
  string t("nagaram");

  //  cout << boolalpha
  //       << is_anagram()

  return 0;
}
