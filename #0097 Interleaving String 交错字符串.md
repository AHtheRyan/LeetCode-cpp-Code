### 交错字符串
### Interleaving String

> 给定三个字符串 `s1`、`s2`、`s3`，请你帮忙验证 `s3` 是否是由 `s1` 和 `s2` **交错**组成的。  
> 两个字符串 `s` 和 `t` **交错**的定义与过程如下，其中每个字符串都会被分割成若干**非空**子字符串：  
> - `s = s1 + s2 + ... + sn`  
> - `t = t1 + t2 + ... + tm`  
> - `|n - m| <= 1`  
> - **交错** 是 `s1 + t1 + s2 + t2 + s3 + t3 + ...` 或者 `t1 + s1 + t2 + s2 + t3 + s3 + ...`  
> 
> **注意**: `a + b` 意味着字符串 `a` 和 `b` 连接。  

> Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an interleaving of `s1` and `s2`.  
> An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:  
> - `s = s1 + s2 + ... + sn`  
> - `t = t1 + t2 + ... + tm`  
> - `|n - m| <= 1`  
> - The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`  
> 
> **Note**: `a + b` is the concatenation of strings `a` and `b`.  

----------

#### I 动态规划

考虑构建DP数组解决问题，首先确定两个字符串的长度 `m` 和 `n`，比较其和与 `s3` 长度的关系，不满足相等关系则肯定不符合拼接条件  
接下来构建动态规划数组 `dp[m + 1][n + 1]`，考虑空字符串必然满足拼接规则，则有 `dp[0][0] = true`  
接下来进行初始化，对于单独一个字符串 `s1` 或者 `s2`，只有对应位置与 `s3` 相同才能符合拼接条件，这样可以完成 `dp[i][0]` 和 `dp[0][i]` 的初始化  
动态规划过程如下：  
如果在当前位置 `dp[i][j]`，存在 `dp[i - 1][j]` 和 `dp[i][j - 1]` 任意一个值为 `true`，则可以比较 `s3` 的当前位置 `s3[i + j - 1]` 与减去一个下标的字符串的当前位置 `s1[i - 1]` 或 `s2[j - 1]`，  
如果两者有一个符合条件，则说明当前位置可以通过拼接形成 `s3` 的字串  
通过此方式一直判断到 `s3` 的最后即可  

```cpp
bool isInterleave(string s1, string s2, string s3) 
{
    int m = s1.size();
    int n = s2.size();
    int len = s3.size();
    if(m + n != len)
        return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for(int i = 1; i <= m && s1[i - 1] == s3[i - 1]; ++i)
        dp[i][0] = true;
    for(int i = 1; i <= n && s2[i - 1] == s3[i - 1]; ++i)
        dp[0][i] = true;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                dp[i][j] = true;
            if(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                dp[i][j] = true;
        }
    }
    return dp[m][n];
}
```
