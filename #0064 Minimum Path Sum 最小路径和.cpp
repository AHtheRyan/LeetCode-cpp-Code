/*
    this question is a derivation of #61 ,the difference is that you can obtain energy by arriving at a certain position,
    using dynamic programming to ensure we can get the minimum energy no matter which place we are in,
    in other words, we can compare the left and the above energy, take the smaller one and add it to current energy as the current whole energy
*/
/*
    此题为 #61 的延伸，区别在于现在每走一步都需要获得格子上的数字（视为能量），
    采用动态规划，保证每一部所取的能量都是在该位置能取到的最小能量即可，
    换句话说，需要比较每一个格子左侧和上侧那个位置的能量比较小再将本位置的能量加上该较小能量，作为本位置的能量值
*/

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; ++i)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int row = 1; row < m; ++row)
        for (int col = 1; col < n; ++col)
            dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
    return dp[m - 1][n - 1];
}