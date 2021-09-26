### 两个字符串的删除操作
### Delete Operation for Two Strings

> 给定两个单词 *word1* 和 *word2*，找到使得 *word1* 和 *word2* 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符  

> Given two strings `word1` and `word2`, return *the minimum number of **steps** required to make `word1` and `word2` the same*.  
> In one **step**, you can delete exactly one character in either string.  

----------

#### I 动态规划

可以直接转化为 [#1143 最长公共子序列](./%231143%20Longest%20Common%20Subsequence%20最长公共子序列.cpp)  
求出最长公共子串，之后两个字符串的多余部分即为需要进行删除的操作次数  

```cpp
int minDistance(string word1, string word2) 
{
    int a = word1.size();
    int b = word2.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    for(int i = 1; i <= a; ++i)
    {
        for(int j = 1; j <= b; ++j)
        {
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] +1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int maxlen = dp[a][b];
    return a + b - maxlen * 2;
}
```

第二种动态规划思路为直接将 `dp` 数组设定为**需要删除的字符数目**，思路如下：  
1. 任意字符串和空字符串的最小删除次数为该字符串的长度，依此将 `dp` 数组初始化  
2. 对于长度分别为 `i` 和 `j` 的字符串：  
   - 如果两个字符相同，那么需要删除的字符总数和考虑这两个字符之前相同，即 `dp[i][j] == dp[i - 1][j - 1]`  
   - 如果两个字符串不同，那么需要删除的字符总数为 `i - 1` 与 `j` 相比需要删除的字符数和 `i` 与 `j - 1` 相比需要删除的字符数的中较小的那个加一  

按此规律构建动态规划数组即可

```cpp
int minDistance(string word1, string word2) 
{
    int a = word1.size();
    int b = word2.size();
    vector<vector<int>> dp(a + 1, vector<int>(b + 1));
    for(int i = 0; i <= a; ++i)
        dp[i][0] = i;
    for(int j = 0; j <= b; ++j)
        dp[0][j] = j;
    for(int i = 1; i <= a; ++i)
    {
        for(int j = 1; j <= b; ++j)
        {
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[a][b];
}
```
