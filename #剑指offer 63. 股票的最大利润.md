### 股票的最大利润

> 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？  

----------

#### I 动态规划

见[买卖股票的最佳时机](./%230121%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20买卖股票的最佳时机.md)  

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
