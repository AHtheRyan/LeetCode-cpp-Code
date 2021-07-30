/*
    since we can reach every place except the start point from its left or above position,
    every position in the first row and column can be reached with one way,
    the possible ways to reach each of the remaining positions are the sum of the ways that the upper and left positions can be reached,
    so we can directly create a 2D array, initialize the array and derive the number of ways of the last position
*/
/*
    �����κ�һ��λ�ã������֮�⣩��ֻ�п���������߻��������λ���ƶ������˳��˵�һ�к͵�һ��ÿ��λ�ö�ֻ��һ�ַ�������֮�⣬
    ����ÿ��λ�õĵ�����ܷ���������������������λ���ܹ�����ķ���֮�ͣ�
    ֱ�Ӵ�����ά���飬��������˼·��ʼ�����������һ��λ�õķ����������Ƴ�������
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