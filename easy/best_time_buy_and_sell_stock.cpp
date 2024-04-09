#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
  int profit = 0;
  int buy = prices[0];
  for(int i = 1; i < prices.size(); ++i) {
    if(profit < prices[i] - buy) {
      profit = prices[i] - buy;
    }

    if(buy > prices[i]) {
      buy = prices[i];
    }
  }

  return profit;
}

int main() {
  // output = 5
  vector<int> prices1{7,1,5,3,6,4};

  // output = 0
  vector<int> prices2{7,6,4,3,1};

  cout << "best time to buy and sell stock: " << maxProfit(prices2) << endl;

  return 0;
}
