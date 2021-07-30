/*
    this question is a derivation of #62 ,the difference is the obstacles,
    if there is obstacle at the start point or the destination, we cannot finish the movement,
    consider other possiblitilies, if there is obstacle at a certain place, then the position below it or at its rightside cannot be reached from it,
    so we can set the obstacle plcace as 0,
    we can get the result with the idea by deriving the whole array
*/
/*
    此题为 #62 的延伸，区别在于障碍物的设计，
    显然，如果障碍物在起点或者终点，那么就无法实现起点->终点的过程，
    考虑其他情况，如果某个位置存在障碍物，那么其右侧和下侧就不能通过该位置到达，因此将该位置的方法直接设为0即可，
    按照上述思路初始化、递推整个数组即可

*/

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    if (obstacleGrid[0][0] == 1)
        return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[m - 1][n - 1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n));
    bool ob = false;
    for (int i = 0; i < m; ++i)
    {
        if (obstacleGrid[i][0] == 1)
            ob = true;
        if (ob)
            dp[i][0] = 0;
        else
            dp[i][0] = 1;
    }
    ob = false;
    for (int i = 0; i < n; ++i)
    {
        if (obstacleGrid[0][i] == 1)
            ob = true;
        if (ob)
            dp[0][i] = 0;
        else
            dp[0][i] = 1;
    }
    for (int row = 1; row < m; ++row)
    {
        for (int col = 1; col < n; ++col)
        {
            if (obstacleGrid[row][col] == 1)
                dp[row][col] = 0;
            else
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
    }
    return dp[m - 1][n - 1];
}