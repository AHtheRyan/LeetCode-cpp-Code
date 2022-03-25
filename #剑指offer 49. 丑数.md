### 丑数

> 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。  

----------

#### I 动态规划

见[丑数II](./%230264%20Ugly%20Number%20II%20丑数II.md)  

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
