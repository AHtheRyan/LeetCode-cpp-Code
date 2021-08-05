/*
    根据题意容易知道，每个完全平方数本身的最小组成数字为 1 ，而第一个数字 1 本身的最小组成数字也是 1，
    建立DP方程，以每个数字 n 的最小组成为结果，分析大于 1 的数字，可知对任何一个数字 n ：
    1. 其组成数字的成分都在 1 和 根号n 之间，并且其组成最少为 dp[1] + dp[n - 1]、dp[2] + dp[n - 2]...中的最小者，
    建立一个双循环，创建 DP 递推公式即可
*/

int numSquares(int n)
{
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int minn = INT_MAX;
        for (int j = 1; j * j <= i; ++j)
            minn = min(minn, dp[i - j * j]);
        dp[i] = minn + 1;
    }
    return dp[n];
}