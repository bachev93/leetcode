#include <iostream>
#include <string>

using namespace std;

// BEST, my approach
int strStr(string haystack, string needle) {
  if (needle.size() > haystack.size()) {
    return -1;
  }

  for (size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
    string sub = haystack.substr(i, needle.size());
    if (needle == sub) {
      return i;
    }
  }

  return -1;
}

int main() {
  const string haystack{"sadbutsad"};
  const string needle{"sad"};

  const auto res = strStr(haystack, needle);
  cout << "res = " << res << endl;
}
