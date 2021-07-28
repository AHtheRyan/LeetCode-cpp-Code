/*
    a simple DP problem, just be aware of the boundary of variables
*/
/*
    一道简单的动态规划题目，注意边界条件维护即可
*/

int minFallingPathSum(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    vector<vector<int>> dp(size, vector<int>(size));
    for (int i = 0; i < size; ++i)
        dp[0][i] = matrix[0][i];

    for (int row = 1; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            if (col == 0)
                dp[row][col] = matrix[row][col] + min(dp[row - 1][0], dp[row - 1][1]);
            else if (col == size - 1)
                dp[row][col] = matrix[row][col] + min(dp[row - 1][col], dp[row - 1][col - 1]);
            else
                dp[row][col] = matrix[row][col] + min(dp[row - 1][col], min(dp[row - 1][col + 1], dp[row - 1][col - 1]));
        }
    }
    return *min_element(dp[size - 1].begin(), dp[size - 1].end());
}