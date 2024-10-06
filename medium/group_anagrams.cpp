#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> anagram_map;
  for (const auto& str : strs) {
    string key_str{str};
    sort(key_str.begin(), key_str.end());
    anagram_map[key_str].push_back(str);
  }

  vector<vector<string>> result;
  for (auto& [_, anagrams] : anagram_map) {
    result.push_back(std::move(anagrams));
  }

  return result;
}

int main() {
  //  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<string> strs{"", ""};

  auto res = groupAnagrams(strs);

  for (auto i = 0u; i < res.size(); ++i) {
    cout << "i: ";
    for (const auto& word : res[i]) {
      cout << word << ", ";
    }
    cout << endl;
  }

  return 0;
}
