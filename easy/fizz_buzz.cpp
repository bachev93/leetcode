#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<string> fizz_buzz(int n) {
  vector<string> res(n);
  for (auto i = 1u; i < res.size() + 1; ++i) {
    const auto div_by_3 = i % 3 == 0;
    const auto div_by_5 = i % 5 == 0;
    if (div_by_3 && div_by_5) {
      res[i - 1] = "FizzBuzz";
    } else if (div_by_3) {
      res[i - 1] = "Fizz";
    } else if (div_by_5) {
      res[i - 1] = "Buzz";
    } else {
      res[i - 1] = to_string(i);
    }
  }
  return res;
}

// another approach
vector<string> fizz_buzz2(int n) {
  vector<string> res(n);
  for (auto i = 1u; i < res.size() + 1; ++i) {
    string ans;
    const auto div_by_3 = i % 3 == 0;
    const auto div_by_5 = i % 5 == 0;

    if (div_by_3) {
      ans += "Fizz";
    }
    if (div_by_5) {
      ans += "Buzz";
    }
    if (ans.empty()) {
      ans = to_string(i);
    }

    res[i - 1] = std::move(ans);
  }
  return res;
}

int main() {
  const auto vals = fizz_buzz(15);
  cout << "Return: " << endl << "[" << endl;
  for (const auto& str : vals) {
    cout << str << "," << endl;
  }
  cout << "]" << endl;

  return 0;
}
