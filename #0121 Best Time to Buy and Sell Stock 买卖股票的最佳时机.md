###  买卖股票的最佳时机
### Best Time to Buy and Sell Stock

> 给定一个数组 `prices`，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。  
> 你只能选择**某一天**买入这只股票，并选择在**未来的某一个不同的日子**卖出该股票。设计一个算法来计算你所能获取的最大利润。  
> 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0`。  

> You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.  
> You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.  
> Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

----------

#### I 动态规划

最大利润为 `prices_max - prices_min`，但需要注意的问题是，此 `max` 值必须在 `min` 值出现之后，  
这也就意味着我们找到 `prices_min` 和他右侧的 `prices_max` 求差即可，  
本题可以引入两个变量，分别记录 `prices` 的当前最小值 `minp` 和当前的利润值 `ret`，之后遍历数组即可找到最大值更新 `minp` 和 `ret` 即可求出最大利润  

```cpp
int maxProfit(vector<int>& prices) 
{
    int minp = INT_MAX;
    int ret = 0;
    for(auto& price : prices)
    {
        minp = min(minp, price);
        ret = max(ret, price - minp);
    }
    return ret;
}
```
