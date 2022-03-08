### 整数拆分
### Integer Break

> 给定一个正整数 `n`，将其拆分为 `k` 个**正整数**的和（`k >= 2`），并使这些整数的乘积最大化。  
> 返回*你可以获得的最大乘积*。  

> Given an integer `n`, break it into the sum of `k` positive integers, where `k >= 2`, and maximize the product of those integers.  
> Return *the maximum product you can get*.  

----------

#### I 动态规划（其他方法可以参考[剪绳子](%23剑指offer%2014.%20剪绳子.md)）

分析任何一个整数，可以发现：  
1. `2` 的拆分只能是 `1 + 1`，最后乘积为 `1`   
2. 从 `3` 开始，每个数字 `n` 的拆分都可以是 `1 + (n - 1)`, `2 + (n - 2)`, `3 + (n - 3)`,...  

如果我们从小到大求出每个数字的最大乘积，那么对于数字 `n`，任何小于他的数字的最大乘积都是已知的，  
这时候只需要比较不同拆分组和中乘积最大的即可，  
按照上述思路构建DP方程  

```cpp
int integerBreak(int n)
{
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i)
        for (int j = 1; j <= i / 2; ++j)
            dp[i] = max(dp[i], max(dp[i - j], i - j) * j);

    return dp[n];
}
```
