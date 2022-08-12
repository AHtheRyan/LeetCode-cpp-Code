### 零钱兑换
### Coins Change

> 给你一个整数数组 `coins`，表示不同面额的硬币；以及一个整数 `amount`，表示总金额。  
> 计算并返回可以凑成总金额所需的**最少的硬币个数**。如果没有任何一种硬币组合能组成总金额，返回 `-1`。  

> You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.  
> Return *the fewest number of coins that you need to make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `-1`.  

----------

#### I 动态规划

对于每个面额的钱，分析其兑换的值：  
1. 如果面额为 0，则只有 1 种方法，即不兑换  
2. 如果面额小于最小值，则没有方法获得该面额的零钱  
3. 如果面额大于最小值，则可以查看面额减去一个最小值之后能否有方法获得，而减去最小值之后的方法已经记录了  
4. 如果面额更大，分别减去每一个小于他的零钱数，再对比看哪种拆分最小即可  

按照上述规律构建DP数组即可

```cpp
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
```
