#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool is_valid(string s) {
  const unordered_map<char, char> parenthesses = {
      {'{', '}'},
      {'(', ')'},
      {'[', ']'},
  };

  stack<char> stk;
  for (const auto sign : s) {
    if (!stk.empty() && parenthesses.count(stk.top()) &&
        parenthesses.at(stk.top()) == sign) {
      stk.pop();
    } else {
      stk.push(sign);
    }
  }

  return stk.empty() ? true : false;
}

int main() {
  //  string str("([)]");
  string str("([)");
  cout << boolalpha << is_valid(str) << endl;

  return 0;
}
