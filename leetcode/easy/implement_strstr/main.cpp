#include <iostream>
#include <string>

using namespace std;

int str_str(string haystack, string needle) {
  if (needle.empty()) {
    return 0;
  }

  const auto pos = haystack.find(needle);
  return (pos == string::npos) ? -1 : pos;
}

int main() {
  string haystack("aaaaaaaaaa");
  string needle("bba");

  cout << "pos: " << str_str(haystack, needle) << endl;
  return 0;
}
