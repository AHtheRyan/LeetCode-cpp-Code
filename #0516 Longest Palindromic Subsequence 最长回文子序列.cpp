/*
    此题类似 #5最长回文子串，区别在于由于考虑的是子序列而不是子串，所以只要s[i] = s[j]，那么DP数组的长度可以直接+2，
    否则DP数组的长度与i和j所包围的子序列的最长回文序列长度有关，
    以上面的条件构建DP数组即可
*/ 

int longestPalindromeSubseq(string s)
{
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size));
    for (int i = size - 1; i >= 0; --i)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < size; ++j)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][size - 1];
}