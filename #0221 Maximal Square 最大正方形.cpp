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
    ���ĳλ�������� 0 ����ô��λ�ò������γ������Σ������λ���� 1 �����γ� 1 �������Σ���
    ���һ�� 1 �����������γ�һ�� 2 �������Σ���ô�����ϡ��ϲ������λ�ö���һ�� 1 �������Σ�
    ���һ�� 1 �����������γ�һ�� 3 �������Σ���ô�����ϡ��ϲ������λ�ö���һ�� 2 �������Σ�
    ���һ�� 1 �����������γ�һ�� n �������Σ���ô�����ϡ��ϲ������λ�ö���һ�� n-1 �������Σ�
    �Դ����ƣ���ô����������ϡ��ϲ���������ֲ�ͬ����ô��λ�����γ� min(���ϣ� �ϲ࣬ ���)+1 �������Σ�
    ��Ϊ��������ζ�С���ǰ�����ϵ��������ÿ��λ����Ϊ���½����γɵ������α߳�Ϊ��������̬�滮���㷨�������Ƴ�
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