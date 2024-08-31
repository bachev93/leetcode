#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& str) {
  vector<string> res;
  string word;
  for (auto c : str) {
    if (isalpha(c)) {
      word += c;
    } else {
      if (!word.empty()) {
        res.push_back(std::move(word));
        word.clear();
      }
    }
  }
  if (!word.empty()) {
    res.push_back(std::move(word));
  }

  return res;
}

int main() {
  auto res = split("hello, world,    ga");
  //  auto res = split(",,,,,,,,,,,,,,,,,,,,,");
  //  auto res = split("helloooo");
  //  auto res = split("              l");

  for (const auto& s : res) {
    cout << s << endl;
  }

  return 0;
}
