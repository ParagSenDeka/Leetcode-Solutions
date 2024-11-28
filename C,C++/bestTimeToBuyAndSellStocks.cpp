#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int currentPrice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < currentPrice)
            {
                currentPrice = prices[i];
            }
            else if (prices[i] - currentPrice > profit)
            {
                profit = prices[i] - currentPrice;
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4, 100};
    Solution sol;
    cout << sol.maxProfit(prices);
}