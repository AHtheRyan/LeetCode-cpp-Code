### 编辑距离
### Edit Distance

> 给你两个单词 `word1` 和 `word2`，*请返回将 `word1` 转换成 `word2` 所使用的最少操作数*。  
> 你可以对一个单词进行如下三种操作：  
> - 插入一个字符  
> - 删除一个字符  
> - 替换一个字符  

> Given two strings `word1` and `word2`, return *the minimum number of operations required to convert `word1` to `word2`*.  
> You have the following three operations permitted on a word:  
> - Insert a character  
> - Delete a character  
> - Replace a character

----------

从 `word1` 变到 `word2`，在某种意义上是先找到最大公共子序列，然后再根据子序列的元素对原字符串的分隔分别处理不同的区间，  
显然，如果考虑不同字符串之间的关系，较长字符串是与较短字符串相关联的,可基于此构建动态规划数组 `dp`，记录最小编辑距离  
当比较两个字符串的某一位时，有如下考虑：  
1. 两个字符相同，则说明两个字符之间不需要经过变换，则可以直接由 `dp[i][j] = dp[i - 1][j - 1]` 获得当前编辑距离  
2. 两个字符不同，则说明两个字符之间需要经过变换，则次数必然加一，此时最小的编辑距离为 `dp[i - 1][j - 1]/dp[i - 1][j]/dp[i][j - 1]` 三个的最小距离加一  

```cpp
int minDistance(string word1, string word2) 
{
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for(int j = 0; j <= n; ++j)
        dp[0][j] = j;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[m][n];
}
```
