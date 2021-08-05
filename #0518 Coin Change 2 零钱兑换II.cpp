/*
    此题方法与 #377 组合总和IV 相同，
    将遍历的顺序改变，可以防止出现相同面额的零钱组成
*/

int change(int amount, vector<int>& coins)
{
    int size = coins.size();
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i = 0; i < size; ++i)
        for (int j = coins[i]; j <= amount; ++j)
            dp[j] += dp[j - coins[i]];
    return dp[amount];
}