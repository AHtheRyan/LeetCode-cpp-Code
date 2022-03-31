### 不同的子序列
### Distinct Subsequences

> 给定一个字符串 `s` 和一个字符串 `t`，计算在 `s` 的子序列中 `t` 出现的个数。  
> 字符串的一个**子序列**是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，`"ACE"` 是 `"ABCDE"` 的一个子序列，而 `"AEC"` 不是）  

> Given two strings `s` and `t`, return *the number of distinct subsequences of `s` which equals `t`*.  
> A string's **subsequence** is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., `"ACE"` is a subsequence of `"ABCDE"` while `"AEC"` is not).  

----------

#### I 动态规划

利用动态规划可解决此问题，设dp数组 `dp[m][n]`，其中，`m` 为 `s` 的长度，`n` 为 `t` 的长度  
且dp数组 `dp[i][j]` 表示从 `s` 的第 `i` 位到末尾的子字符串和从 `t` 的第 `j` 位到末尾的子字符串的对应结果  
根据题目条件可知对任意 `i` `j` 有 `dp[i][n] = 1`，`dp[m][j] = 0`  
分析其他一般情况：  
1. 如果 `s[i] != t[j]`，说明此对字符不能完成匹配，则实际匹配的可能性为不包含 `s[i]` 的 `s` 后面字符串和包含 `t[j]` 的 `t` 后面的字符串的匹配可能性，即 `dp[i][j] = dp[i + 1][j]`  
2. 如果 `s[i] == t[j]`，说明此对字符能完成匹配，则实际匹配的情况为上述可能（假定不匹配），和实际能匹配成功的可能性的总和，即 `dp[i][j] = dp[i + 1][j] + dp[i + 1][j+ 1]`  

```cpp
int numDistinct(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    if(m < n)   return 0;
    vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
    for(int i = 0; i <= m; ++i)
        dp[i][n] = 1;
    for(int i = m - 1; i >= 0; --i)
    {
        for(int j = n - 1; j >= 0; --j)
        {
            if(s[i] != t[j])
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
        }
    }
    return dp[0][0];
}
```
