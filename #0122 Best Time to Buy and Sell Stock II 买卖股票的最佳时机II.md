### 买卖股票的最佳时机 II
### Best Time to Buy and Sell Stock II

> 给定一个数组 `prices`，其中 `prices[i]` 是一支给定股票第 `i` 天的价格。  
> 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。  
> **注意**：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。  

> You are given an array `prices` where `prices\[i]` is the price of a given stock on the `ith` day.  
> Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).  
> **Note**: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).  

----------

#### I 动态规划
#### I Dynamic Programming

最大利润为每个区间内 prices_max - prices_min 的和，但需要注意的问题是，每一个 max 值必须在 min 值出现之后，  
这也就意味着我们找到 prices_min 和他右侧暂时的 prices_max 求差，并将每次的结果求和即可，  
本题引入两个变量，存储每一天持有 (k) 或者不持有 (nk) 股票身上的总额，每天的总额可以根据前一天是否持有和不持有以及今天持有或不持有决定，取较大者，  
最后不持有股票时身上钱最多的时候就是赚钱最多的时候  

The maximum profit is the sum of prices_max - prices_min in each interval,  
But the problem that needs to be noted is that each prices_max must be after prices_min appears,  
This means that we find the difference between prices_min and the temporary prices_max on his right, and can get the result by summing the results each time,  
We can create two variables to store the total amount of stocks held (k) or not held (nk) each day,  
The total amount of each day can be determined according to whether it is held or not held the previous day and whether it is held or not held today,  
In the end, the result is the money you have when you don’t own stocks  

```cpp
int maxProfit(vector<int>& prices)
{
    int size = prices.size();
    int nk = 0;
    int k = -prices[0];
    int max = 0;
    for (int i = 1; i < size; ++i)
    {
        nk = nk > k + prices[i] ? nk : k + prices[i];
        k = k > nk - prices[i] ? k : nk - prices[i];
        max = nk > max ? nk : max;
    }
    return max;
}
```

#### II 贪心
#### II Greedy Algorithm
根据题意，可以对股票进行任意次数的买入和卖出，  
因此，对于每天的股票价格而言，我们可以存储较低的股票价格：  
如果某一天的股票价格比前一天低，那么就存储该天的股票价格视为买入，如果后面一天的股票价格更低，则继续改成后一天买入，  
如果某一天的股票价格比前一天高，那么就视为当天卖出股票，然后视为当天卖出之后又买入股票，  
这样，即使出现连续股价上升，实质上也就是 第三天 - 第二天 + 第二天 - 第一天 = 第三天 - 第二天，相当于并未违反连续操作的规则，  
利用此方法递推每日的股票价格即可

According to the problem conditions, we can buy and sell stocks any number of times,  
so we can store the lower stock price via variable:  
if current price is lower than previous price, we can store current price and regard as buying, if the next day's price is lower, then we store the lower price,  
if current prices is higher than previous price, we can sell the stock and buy it the same day,  
the result is that, even if the stock's price continue grwoing, we can see our operation as 3rd day - 2nd day + 2nd day - 1st day, which dosen't obey the rules,  
we can get the highest profit in this way

```cpp
int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        int profit = 0;
        int min = prices[0];
        for(int i = 1; i < size; ++i)
        {
            if(prices[i] > min)
                profit += prices[i] - min;
            min = prices[i];
        }
        return profit;
    }
```
