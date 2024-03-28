#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int first_unique_char(string s) {
  unordered_map<char, int> char_cnt;
  for (const auto elem : s) {
    ++char_cnt[elem];
  }

  for (auto i = 0u; i < s.size(); ++i) {
    if (char_cnt[s[i]] == 1) {
      return i;
    }
  }
  return -1;
}

int main() {
  //  string s("leetcode");
  string s("loveleetcode");
  cout << "result: " << first_unique_char(s) << endl;

  return 0;
}
