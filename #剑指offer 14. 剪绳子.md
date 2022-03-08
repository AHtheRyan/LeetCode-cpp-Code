### 剪绳子

> 给你一根长度为 `n` 的绳子，请把绳子剪成整数长度的 `m` 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 `k[0],k[1]...k[m-1]`。请问 `k[0]*k[1]*...*k[m-1]` 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。  

----------

#### I 动态规划

具体分析见[整数拆分](%230343%20Integer%20Break%20整数拆分.md)  

```cpp
int cuttingRope(int n) 
{
    vector<int> dp(n + 1);
    dp[2] = 1;
    for(int i = 3; i <= n; ++i)
        for(int j = 1; j <= i / 2; ++j)
            dp[i] = max(dp[i], max(i - j, dp[i - j]) * max(j, dp[j]));
    return dp[n];
}
```

#### II 数学

根据DP方法的分析可以发现，最后所有的数字被拆分成 `n 个 3 * m 个 2` 的方案  
因此，可以直接对数字 `n` 做除以 `3` 的运算，取 `3` 的余数进行考虑：
1. 余数为 `1`，此时结果为 `m 个 3` 乘以 `1 个 1`，结果为 `3m`，显然，如果拆出一个 `3`，变成 `2 * 2 * 3(m - 1)`，则结果会更大  
2. 余数为 `2`，则此时直接乘到最终结果即可  
3. 余数为 `0`，则此时为最大结果  
 
数学证明可以参考[相关证明](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/)  

```cpp
int cuttingRope(int n) 
{
    if(n <= 3)
        return n - 1;
    if(n % 3 == 0)
        return int(pow(3, n / 3));
    if(n % 3 % 2 == 0)
        return int(pow(3, n / 3) * pow(2, n % 3 / 2));
    return int(pow(3, n / 3 - 1) * pow(2, n % 3 / 2 + 2));
}
```

#### III 迭代

此方法等同数学方法，**适用于数字特别大的场合**  
答案需要取模 `1e9+7（1000000007）`  

```cpp
class Solution 
{
public:
    static constexpr int mod = 1000000007;

    int cuttingRope(int n) 
    {
        if(n <= 3)
            return n - 1;
        long ret = 1;
        while(n / 3 > 1)
        {
            ret *= 3;
            ret %= mod;
            n -= 3;
        }
        if(n % 3 == 1)
            ret *= 4;
        else if(n % 3 == 2)
            ret *= 6;
        else
            ret *= 3;
        return ret % mod;
    }
};
```
