/*
    �������� #5������Ӵ��������������ڿ��ǵ��������ж������Ӵ�������ֻҪs[i] = s[j]����ôDP����ĳ��ȿ���ֱ��+2��
    ����DP����ĳ�����i��j����Χ�������е���������г����йأ�
    ���������������DP���鼴��
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