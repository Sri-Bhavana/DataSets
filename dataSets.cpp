
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for (int price : prices) {
        min_price = min(min_price, price);  // Update min if a lower price is found
        max_profit = max(max_profit, price - min_price);  // Calculate profit for current price
    }

    return max_profit;
}

int main() {
    vector<int> prices = { 10, 7, 5, 8, 11, 9 };

    cout << "Maximum profit from the given list of stock prices is: " << maxProfit(prices) << endl;

    return 0;
}
