#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// simple solution
string longest_common_prefix(vector<string>& strs) {
  if (strs.empty()) {
    return "";
  }

  auto pref = strs[0];
  for (auto i = 1u; i < strs.size(); ++i) {
    bool is_pref = false;
    while (!is_pref) {
      auto pos = strs[i].find(pref);
      if (pos != 0) {
        pref = pref.substr(0, pref.size() - 1);
        if (pref.empty()) {
          return "";
        }
      } else {
        is_pref = true;
      }
    }
  }

  return pref;
}

// another approach
string longest_common_prefix2(vector<string>& strs) {
  if (strs.empty()) {
    return "";
  }

  string prefix;
  sort(strs.begin(), strs.end());
  const auto& first_word = strs.front();
  const auto& last_word = strs.back();
  for (auto i = 0u; i < min(first_word.size(), last_word.size()); ++i) {
    if (first_word[i] == last_word[i]) {
      prefix += first_word[i];
    } else {
      break;
    }
  }

  return prefix;
}

int main() {
  vector<string> strs = {"flower", "flow", "flight"};
  //  vector<string> strs = {"c", "acc", "ccc"};

  const auto result = longest_common_prefix(strs);
  if (result.empty()) {
    cout << "empty prefix" << endl;
  }
  cout << result << endl;
  return 0;
}
