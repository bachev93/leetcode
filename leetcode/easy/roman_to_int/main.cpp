#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

namespace {
const unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
}

int roman_to_int(string s) {
  auto result = 0;
  for (auto i = 0u; i < s.size(); ++i) {
    auto curr = roman.at(s[i]);

    if (i > 0) {
      auto prev = roman.at(s[i - 1]);

      if (curr > prev) {
        curr -= prev * 2;
      }
    }

    result += curr;
  }

  return result;
}

int main() {
  // 1994
  cout << roman_to_int("MCMXCIV") << endl;

  return 0;
}
