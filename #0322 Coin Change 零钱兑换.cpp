/*
    对于每个面额的钱，分析其兑换的值：
    1. 如果面额为 0，则只有 1 种方法，即不兑换
    2. 如果面额小于最小值，则没有方法获得该面额的零钱
    3. 如果面额大于最小值，则可以查看面额减去一个最小值之后能否有方法获得，而减去最小值之后的方法已经记录了
    4. 如果面额更大，分别减去每一个小于他的零钱数，再对比看哪种拆分最小即可
    按照上述规律构建DP数组即可
*/

int coinChange(vector<int>& coins, int amount)
{
    int size = coins.size();
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
        for (int j = 0; j < size; ++j)
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
}