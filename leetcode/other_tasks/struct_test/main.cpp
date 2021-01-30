#include <iostream>

using namespace std;

struct Point {
  int x;
  int y;
  bool flag;
};

int main() {
  Point p = {};
  //  Point p;

  cout << p.x << "\t" << p.y << "\t" << p.flag << endl;

  return 0;
}
