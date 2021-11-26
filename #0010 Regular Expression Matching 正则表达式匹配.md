### 正则表达式匹配
### Regular Expression Matching

> 给你一个字符串 `s` 和一个字符规律 `p`，请你来实现一个支持 `'.'` 和 `'*'` 的正则表达式匹配。  
> - `'.'` 匹配任意单个字符  
> - `'*'` 匹配零个或多个前面的那一个元素  
> 
> 所谓匹配，是要涵盖 **整个** 字符串 `s` 的，而不是部分字符串。  

> Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:  
> - `'.'` Matches any single character.  
> - `'*'` Matches zero or more of the preceding element.  
> 
> The matching should cover the **entire** input string (not partial).  

----------

#### I 动态规划

显然，对于字符串长度为 `a` 的字符串和长度为 `b` 的字符串，其是否满足正则匹配必然与 `a - 1` 的子串和 `b - 1` 的子串相关  
因此，考虑采用动态规划的方案进行求解  
我们设二维数组 `dp[m][n]` 为长度为 `m - 1` 和 `n - 1` 的字符串的正则匹配长度，设当前 `s` 和 `p` 的子串位置分别为 `i` 和 `j`，则可将所有的匹配情况分成如下讨论：  
1. `p[j] == '*'`，即当前 `p` 的位置为拓展标志位，根据其含义，第 `j - 1` 位的字符可以出现任意次，所以此时的子串可匹配长度为 `s[i]` 和 `p[j - 2]` 的匹配长度（即考虑 `p[j -1] == 0` 的情况）  
   - 进而，如果第 `j - 1` 位元素，即可以取任意次数的元素与第 `i` 位也匹配，则子串可匹配长度进一步扩展为 `s[i]` 和 `p[j - 1]`的匹配长度  
2. `s[i] == p[j]`（考虑 `'.'` 和字母两种情况），即当前两个字符串的对应位置匹配，则实际匹配长度为 `s[i - 1]` 和 `p[j - 1]` 的长度的延伸  

按照此规则最后将完整长度的字符串匹配结果算出即可

```cpp
bool isMatch(string s, string p) 
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    dp[0][0] = true;

    auto match = [&] (int i, int j)
    {
        if(i == 0)
            return false;
        if(p[j - 1] == '.')
            return true;
        return s[i - 1] == p[j - 1];
    };

    for(int i = 0; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(p[j - 1] == '*')
            {
                dp[i][j] |= dp[i][j - 2];
                if(match(i, j - 1))
                    dp[i][j] |= dp[i - 1][j];
            }
            else if(match(i, j))
                dp[i][j] |= dp[i - 1][j - 1];
        }
    }
    return dp[m][n];
}
```
