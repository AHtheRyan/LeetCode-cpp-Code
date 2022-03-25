### 丑数II
### Ugly Number II

> 给你一个整数 `n`，请你找出并返回第 `n` 个**丑数**。  
> **丑数**就是只包含质因数 `2`、`3` 和/或 `5` 的正整数。  

> An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.  
> Given an integer `n`, return *the `nth` **ugly number***.  

----------

#### I 动态规划


丑数的因数为 `2`、`3` 或者 `5`，因此，每个丑数都应该是 `2`、`3`、`5` 或者他们之间的乘积，  
因此可以用`2`/`3`/`5`作为基底依次乘以每一个前面的丑数，依次取最小的丑数作为下一位的丑数，  
求到第 `n` 个丑数即为我们所要求的的结果  

```cpp
int nthUglyNumber(int n) 
{
    int two = 1;
    int three = 1;
    int five = 1;
    vector<int> dp(n + 1);
    dp[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        int num2 = dp[two] * 2;
        int num3 = dp[three] * 3;
        int num5 = dp[five] * 5;
        dp[i] = min(num2, min(num3, num5));
        if(dp[i] == num2)   ++two;
        if(dp[i] == num3)   ++three;
        if(dp[i] == num5)   ++five;
    }
    return dp[n];
}
```
