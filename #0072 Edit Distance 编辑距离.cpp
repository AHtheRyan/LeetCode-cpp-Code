/*
    从 word1 变到 word2，在某种意义上是先找到最大公共子序列，然后再根据子序列的元素对原字符串的分隔分别处理不同的区间，
    显然，如果考虑不同字符串之间的关系，较长字符串是与较短字符串相关联的，如长度分别为 x 和 y 的字符串的编辑距离肯定与 x-1 y-1 的子串相关，
    因此可以根据他们之间的关系，找出规律，构建DP方程
*/ 

int minDistance(string word1, string word2)
{
    int size1 = word1.size();
    int size2 = word2.size();
    if (!size1 || !size2)
        return size1 + size2;
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
    for (int i = 0; i <= size1; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= size2; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= size1; ++i)
    {
        for (int j = 1; j <= size2; ++j)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[size1][size2];
}