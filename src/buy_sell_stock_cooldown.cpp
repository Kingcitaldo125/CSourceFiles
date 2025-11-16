// https://neetcode.io/problems/buy-and-sell-crypto-with-cooldown?list=neetcode150
#include <algorithm>
#include <iostream>
#include <vector>

int maxProfitHelp(const std::vector<int>& prices, const int state, const int hold, const int profit)
{
    if (prices.empty())
        return profit;

    std::vector<int> holdings{0};
    for(auto it = prices.begin(); it < prices.end(); ++it)
    {
        const auto xvec = std::vector<int>(it + 1, prices.end());
        const int price = *it;
        if (state == 0) // can buy
        {
            holdings.push_back(maxProfitHelp(xvec, 1, price, profit)); // choose to buy
            holdings.push_back(maxProfitHelp(xvec, 2, hold, profit)); // choose to wait
        }
        else if (state == 1) // can sell
        {
            holdings.push_back(maxProfitHelp(xvec, 1, hold, profit)); // choose to wait
            holdings.push_back(maxProfitHelp(xvec, 2, 0, profit + (price - hold))); // choose to sell
        }
        else if (state == 2) // else -- cooldown.
        {
            holdings.push_back(maxProfitHelp(xvec, 0, 0, profit));
        }
    }
    return *std::max_element(holdings.begin(),holdings.end());
}

int maxProfit(const std::vector<int>& prices)
{
    return maxProfitHelp(prices, 0, 0, 0);
}

int main()
{
    std::cout << maxProfit({1,3,4,0,4}) << "\n";
    return 0;
}
