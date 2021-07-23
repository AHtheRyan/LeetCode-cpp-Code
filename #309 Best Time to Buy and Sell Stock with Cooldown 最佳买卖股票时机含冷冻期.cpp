/*
    please refer to #122The Best Time to Buy and Sell Stocks II before solving this problem,
    similar to that question, the situation that we need to consider here can be divided into three categories:
    1. No stocks are held on that day, and it is a no-cooldown period
    2. Hold stocks on the day
    3. No stocks are held on the day, and it is the cooldown period
    the relationship between the maximum profit of each day and the state of the previous day is as follows:
    1. Do not hold stocks on the day + no-cooldown period, 
       which means that you must not hold stocks the day before (otherwise it will be the cooldown period), 
       so take the larger one between the cooldown and no-cooldown profit of the day;
    2. Holding the stock on the same day,
       which means that the previous day must not be in the cooldown period (otherwise it cannot be bought),
       so take the larger one between held-in-the-previous-day or  did-not-held-the-previous-day profit；
    3. Do not hold stocks on the day + cooldown period,
       which means that the stocks must be sold the day before,
       so the profit of the day is the profit of holding the stocks the day before + the money earned from selling the stocks the day
    traverse the array and take the maximum profit on the last day when you don’t hold stocks.
*/
/*
    做此题之前请先参阅 #122买卖股票的最佳时机II，
    与该题类似，我们在这里需要考虑情况分为三类：
    1. 当天不持有股票，且为非冷冻期
    2. 当天持有股票
    3. 当天不持有股票，且为冷冻期
    每一天的最大利润与之前一天的状态关系如下：
    1. 当天不持有股票 + 非冷冻期，意味着前一天必然是不持有股票的（否则一定进入冷冻期），所以取前一天不持有股票时的较大利润为当天最大利润；
    2. 当天持有股票，意味着前一天必然不是冷冻期（否则不能买），所以取前一天持有的利润或者前一天不持有但今天花钱买了之后的利润二者的较大利润；
    3. 当天不持有股票 + 冷冻期，意味着前一天必然卖了股票，所以当天的利润为前一天持有股票的利润加上当天卖出股票赚的钱
    遍历数组，取不持有股票时最后一天的最大利润即可
*/

int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    vector<vector<int>> dp(size, vector<int>(3));
    dp[0][0] = 0;   //not held + no-cooldown    //不持有 + 非冷冻期
    dp[0][1] = -prices[0];  //held    //持有
    dp[0][2] = 0;   //not held + cooldown   //不持有 + 冷冻期
    for (int i = 1; i < size; ++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        dp[i][2] = dp[i - 1][1] + prices[i];
    }
    return max(dp[size - 1][0], dp[size - 1][2]);
}