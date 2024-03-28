#include <iostream>

using namespace std;

int main() {
  char a, b;
  char const *cpc = &a;
  cpc = &b;
  //  *cpc = 'z';
  return 0;
}
