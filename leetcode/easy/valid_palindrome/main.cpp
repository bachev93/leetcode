#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome(string s) {
  string tmp_str;
  for (const auto c : s) {
    if (isalnum(c)) {
      tmp_str.push_back(tolower(c));
    }
  }

  for (auto i = 0u; i < tmp_str.size(); ++i) {
    if (tmp_str[i] != tmp_str[tmp_str.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

int main() {
  //  string s("A man, a plan, a canal: Panama");
  //  string s("abba");
  //  string s("not palindrome");
  string s("0P");

  cout << boolalpha << is_palindrome(s) << endl;
  return 0;
}
