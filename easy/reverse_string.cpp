#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void reverse_string(vector<char>& s) { reverse(s.begin(), s.end()); }

void reverse_string2(vector<char>& s) {
  for (auto i = 0u; i < s.size() / 2; ++i) {
    const auto tmp = s[i];
    s[i] = s[s.size() - i - 1];
    s[s.size() - i - 1] = tmp;
  }
}

int main() {
  vector<char> s{'h', 'e', 'l', 'l', 'o'};

  reverse_string2(s);
  for (const auto elem : s) {
    cout << elem << ", ";
  }
  cout << endl;

  return 0;
}
