/*
    please refer to #122The Best Time to Buy and Sell Stocks II before solving this problem,
    similar to that question, the situation that we need to consider here can be divided into two categories:
    1. No hold stocks on that day
    2. Hold stocks on the day
    relationship between maximum profit of each day and the previous day is showed below:
    1. Not hold stocks on that day: larger one of profit of not hold stocks in the previous day and hold stocks then sell in the day
    2. Hold stocks on the day: larger one of profit of hold in the previous day and no hold stocks then buy in the day
    we create 4 variables to store the profits of hold and no hold in the day and the previous day,
    the maximum profits appears when we don't hold stocks in the last day
*/

/*
    做此题之前请先参阅 #122买卖股票的最佳时机II，
    与该题类似，我们在这里需要考虑情况分为两类：
    1. 当天不持有股票
    2. 当天持有股票
    每一天的最大利润与之前一天的状态关系如下：
    1. 当天不持有股票：前一天不持有股票和前一天持有当天卖出之间的较大者
    2. 当天持有股票：前一天持有和前一天不持有当天买进之间的较大者
    本题引入四个变量，存储当天和前一天持有 (k) 或者不持有 (nk) 股票身上的总额，最后不持有股票时身上的钱就是最大利润
*/

int maxProfit(vector<int>& prices, int fee)
{
    int size = prices.size();
    vector<vector<int>> dp(size, vector<int>(2));
    int nh = 0;
    int h = -prices[0];
    int pre_nh = nh;
    int pre_h = h;
    for (int i = 1; i < size; ++i)
    {
        nh = max(pre_nh, pre_h + prices[i] - fee);
        h = max(pre_nh - prices[i], pre_h);
        pre_h = h;
        pre_nh = nh;
    }
    return nh;
}