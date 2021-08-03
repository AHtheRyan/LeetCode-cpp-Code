/*
    显然，两个字符串之间最长公共子序列的长度与两字符串的子串相关，
    即如果某个位置两个字符串的字符相同，那么最长公共子序列的值一定是两者除自己外最长的字串形成的最长公共子序列的长度 + 1，
    如果某个位置两个字符串的字符不同，那么最长公共子序列一定是两者和另一个字符串 - 1 之后的子字符串形成的最长公共子序列中的较长者，
    可以以此构建DP方程求解
*/

int longestCommonSubsequence(string text1, string text2)
{
    int size1 = text1.size();
    int size2 = text2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
    dp[0][0] = dp[0][1] = dp[1][0] = 0;
    for (int i = 1; i <= size1; ++i)
    {
        for (int j = 1; j <= size2; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[size1][size2];
}