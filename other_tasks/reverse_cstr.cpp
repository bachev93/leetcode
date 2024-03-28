#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void reverse(char *str) {
  const auto len = strlen(str);
  for (auto i = 0u; i < len / 2; ++i) {
    swap(str[i], str[len - 1 - i]);
  }
}

void reverse2(char *str) {
  const auto len = strlen(str);
  for (auto i = 0u; i < len / 2; ++i) {
    auto tmp = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = tmp;
  }
}

int main() {
  //  char *str = "hello";
  //  char str[] = {'h', 'e', 'l', 'l', 'o', 'w'};
  char str[] = "hellow";

  //  cout << "size of arr: " << sizeof(str) << ", strlen, " << strlen(str) <<
  //  endl;

  cout << "before swap: " << str << endl;
  reverse2(str);
  cout << "after swap: " << str << endl;

  return 0;
}
