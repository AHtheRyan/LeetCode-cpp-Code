/*
    the factors of ugly numbers are 2, 3, or 5, therefore, each ugly number should be 2, 3, 5 or their product,
    therefore, we can use 2/3/5 as the base to multiply each previous ugly number in turn, and take the smallest ugly number as the next ugly number in turn,
    finding the nth ugly number is the result we require
*/
/*
    ����������Ϊ 2��3����5����ˣ�ÿ��������Ӧ����2��3��5��������֮��ĳ˻���
    ��˿�����2/3/5��Ϊ�������γ���ÿһ��ǰ��ĳ���������ȡ��С�ĳ�����Ϊ��һλ�ĳ�����
    �󵽵� n ��������Ϊ������Ҫ��ĵĽ��
*/

int nthUglyNumber(int n)
{
    vector<int> dp(n + 1);
    int pos2 = 1;
    int pos3 = 1;
    int pos5 = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i)
    {
        int num2 = dp[pos2] * 2;
        int num3 = dp[pos3] * 3;
        int num5 = dp[pos5] * 5;
        dp[i] = min(num2, min(num3, num5));
        if (dp[i] == num2)   ++pos2;
        if (dp[i] == num3)   ++pos3;
        if (dp[i] == num5)   ++pos5;
    }
    return dp[n];
}