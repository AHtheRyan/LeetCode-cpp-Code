/*
    this question is a derivation of #62 ,the difference is the obstacles,
    if there is obstacle at the start point or the destination, we cannot finish the movement,
    consider other possiblitilies, if there is obstacle at a certain place, then the position below it or at its rightside cannot be reached from it,
    so we can set the obstacle plcace as 0,
    we can get the result with the idea by deriving the whole array
*/
/*
    ����Ϊ #62 �����죬���������ϰ������ƣ�
    ��Ȼ������ϰ������������յ㣬��ô���޷�ʵ�����->�յ�Ĺ��̣�
    ����������������ĳ��λ�ô����ϰ����ô���Ҳ���²�Ͳ���ͨ����λ�õ����˽���λ�õķ���ֱ����Ϊ0���ɣ�
    ��������˼·��ʼ���������������鼴��

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