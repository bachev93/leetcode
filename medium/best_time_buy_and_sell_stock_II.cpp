#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
  int profit = 0;
  int buy = prices[0];

  for(int i = 1; i < prices.size(); ++i) {
    if(prices[i] > buy) {
      profit += prices[i] - buy;
    }
    buy = prices[i];
  }

  return profit;
}

int main() {
  cout << "best time to buy and sell stock ii:" << endl;

  // expected = 7
  vector<int> prices{7,1,5,3,6,4};

  // expected = 4
  vector<int> prices2{1,2,3,4,5};

  // expected = 0;
  vector<int> prices3{7,6,4,3,1};

  cout << "result = " << maxProfit(prices) << endl;

  return 0;
}