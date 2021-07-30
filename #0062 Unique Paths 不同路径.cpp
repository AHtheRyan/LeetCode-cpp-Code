/*
    since we can reach every place except the start point from its left or above position,
    every position in the first row and column can be reached with one way,
    the possible ways to reach each of the remaining positions are the sum of the ways that the upper and left positions can be reached,
    so we can directly create a 2D array, initialize the array and derive the number of ways of the last position
*/
/*
    由于任何一个位置（除起点之外）都只有可能由其左边或者上面的位置移动到达，因此除了第一行和第一列每个位置都只有一种方法到达之外，
    其余每个位置的到达可能方法都是其上面和左边两个位置能够到达的方法之和，
    直接创建二维数组，利用上述思路初始化，并将最后一个位置的方法总数递推出来即可
*/

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        dp[i][0] = 1;
    for (int i = 0; i < n; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}