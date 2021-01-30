#include <iostream>
#include <map>

using namespace std;

struct Point {
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  bool operator<(const Point &other) const {
    return (x < other.x) && (y < other.y);
  }
  int x, y;
};

int main() {
  map<Point, int> m;
  m.insert(make_pair(Point(0, 1), 1));
  m.insert(make_pair(Point(1, 0), 2));
  cout << m[Point(0, 1)];
  cout << m[Point(1, 0)];
  return 0;
}
