/*
    consider, respectively, how many trees there are with 1, 2, 3, 4, 5, ... as the root node,
    when n is the root node, the number of elements in the left subtree is n-1, and the number of elements in the right subtree is the total number-n,
    traverse in turn and add the probability of each left and right subtree distribution together
*/
/*
    �ֱ����� 1,2,3,4,5������Ϊ���ڵ�����ж��ٸ���
    �� n Ϊ���ڵ�ʱ����������Ԫ����ĿΪ n - 1 ���������� ��Ԫ����ĿΪ ���� - n ����
    ���α�����ÿһ�����������ֲ��Ŀ����Լ���һ�𼴿�
*/

int numTrees(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i] += dp[j - 1] * dp[i - j];
    return dp[n];
}
