#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> storage;
  for (const auto& word : strs) {
    string tmp = word;
    sort(tmp.begin(), tmp.end());
    storage[tmp].push_back(word);
  }

  vector<vector<string>> res;
  for (const auto& [_, val] : storage) {
    res.push_back(move(val));
  }

  return res;
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
