#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool is_valid(string s) {
  const unordered_map<char, char> parentheses = {
      {'{', '}'},
      {'(', ')'},
      {'[', ']'},
  };

  stack<char> stk;
  for (const auto sign : s) {
    if (!stk.empty() && parentheses.count(stk.top()) &&
        parentheses.at(stk.top()) == sign) {
      stk.pop();
    } else {
      stk.push(sign);
    }
  }

  return stk.empty();
}

int main() {
  //  string str("([)]");
  string str("([)");
  cout << boolalpha << is_valid(str) << endl;

  return 0;
}
