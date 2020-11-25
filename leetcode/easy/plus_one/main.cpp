#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> plus_one(vector<int>& digits) {
  ++digits.back();
  for (auto i = digits.size() - 1; i > 0; --i) {
    if (digits[i] == 10) {
      digits[i] = 0;
      ++digits[i - 1];
    } else {
      break;
    }
  }

  if (digits.front() == 10) {
    digits.front() = 0;
    vector<int> res(digits.size() + 1);
    res[0] = 1;
    copy(digits.begin(), digits.end(), ++res.begin());
    return res;
  }
  return digits;
}

int main() {
  vector<int> digits = {9, 8, 9};
  const auto result = plus_one(digits);

  for (const auto elem : result) {
    cout << elem << ", ";
  }
  cout << endl;
  return 0;
}
