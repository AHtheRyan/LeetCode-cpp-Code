/*
    ����ÿ������Ǯ��������һ���ֵ��
    1. ������Ϊ 0����ֻ�� 1 �ַ����������һ�
    2. ������С����Сֵ����û�з�����ø�������Ǯ
    3. �����������Сֵ������Բ鿴����ȥһ����Сֵ֮���ܷ��з�����ã�����ȥ��Сֵ֮��ķ����Ѿ���¼��
    4. ��������󣬷ֱ��ȥÿһ��С��������Ǯ�����ٶԱȿ����ֲ����С����
    �����������ɹ���DP���鼴��
*/

int coinChange(vector<int>& coins, int amount)
{
    int size = coins.size();
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
        for (int j = 0; j < size; ++j)
            if (coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
}