/*
    ������������֪����ÿ��λ���ܷ��ǰ���������ɵ�������ȡ����ǰ��������Ƿ�С�ڸ������Լ�ǰ�����������ȡ������������еĴ�С��
    ��ˣ��Ե�һ�����ֹ��ɵĳ���Ϊ 1 ������Ϊ��ʼ����������DP���̼���
*/

int lengthOfLIS(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    for (int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    return *max_element(dp.begin(), dp.end());
}