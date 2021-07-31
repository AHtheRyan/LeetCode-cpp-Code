/*
    if the number in a certain place is 0, then it cannot form a square, or the number is 1, then it can form at least a 1st-order square,
    if the 1st-order square can form a 2nd-order square, then the number in its left/above/left-above side should be a 1st-order square,
    if the 1st-order square can form a 3rd-order square, then the number in its left/above/left-above side should be a 2nd-order square,
    ...
    so, how it would be if the number is different in the three different position?
    it will be a min(left, above, left-above) + 1-order square,
    wo we create a variable of which order of a square a certain position can form, and we will get the DP function
*/
/*
    如果某位置数字是 0 ，那么该位置不可能形成正方形，如果该位置是 1 ，即形成 1 阶正方形，则：
    如果一个 1 阶正方形能形成一个 2 阶正方形，那么其左上、上侧和左侧的位置都是一个 1 阶正方形，
    如果一个 1 阶正方形能形成一个 3 阶正方形，那么其左上、上侧和左侧的位置都是一个 2 阶正方形，
    如果一个 1 阶正方形能形成一个 n 阶正方形，那么其左上、上侧和左侧的位置都是一个 n-1 阶正方形，
    以此类推，那么，如果其左上、上侧和左侧的数字不同，那么该位置能形成 min(左上， 上侧， 左侧)+1 阶正方形，
    因为大的正方形对小的是包含关系，所以以每个位置作为右下角能形成的正方形边长为变量，动态规划的算法很容易推出
*/ 

int maximalSquare(vector<vector<char>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    int max = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = matrix[i][j] - '0';
            max = max > dp[i][j] ? max : dp[i][j];
        }
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (dp[i][j] == 0)
                continue;
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            max = max > dp[i][j] ? max : dp[i][j];
        }
    }
    return max * max;
}