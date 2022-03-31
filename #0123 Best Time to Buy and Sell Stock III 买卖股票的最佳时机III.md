### 买卖股票的最佳时机III
### Best Time to Buy and Sell Stock III

> 给定一个数组，它的第 `i` 个元素是一支给定的股票在第 `i` 天的价格。  
> 设计一个算法来计算你所能获取的最大利润。你最多可以完成**两笔**交易  
> **注意**：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。  

> You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.  
> Find the maximum profit you can achieve. You may complete at most two transactions.  
> **Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).  

----------

#### I 动态规划

人民群众喜闻乐见的股票买卖问题，直接安排动态规划，  
首先确定状态转移的几个变量，因为一共只进行两次买卖，在这里我们将变量设计为第一次买，第一次卖，第二次买和第二次卖：  
第一次买：第一次买一定是从**0本金**到**负数**，所以只要保证买的时候是亏的最少的就可以  
第一次卖：第一次卖的时候的 `利润 = 当天价格 - 第一次买的价格`，如果该价格比之前储存的价格高，那么取更高的利润  
第二次买：第二次买的时候的利润一定为从第一次赚的钱减去某一天股票的价格，肯定是股票价格越低越好，将其存储  
第二次卖：第二次卖的时候的 `利润 = 当天价格 + 第二次卖的价格`，如果该价格比之前存储的价格高，那么取更高的利润  
返回最后一天第二次卖的利润即可  

```cpp
int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    int hold = -prices[0];
    int hold2 = -prices[0];
    int nothold = 0;
    int nothold2 = 0;
    for (int i = 1; i < size; ++i)
    {
        hold = max(hold, -prices[i]);
        nothold = max(nothold, hold + prices[i]);
        hold2 = max(hold2, nothold - prices[i]);
        nothold2 = max(nothold2, hold2 + prices[i]);
    }
    return nothold2;
}
```
