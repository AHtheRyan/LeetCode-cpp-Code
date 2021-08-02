/*
    根据题意容易知道，每个位置能否和前面的数字组成递增序列取决于前面的数字是否小于该数字以及前面的数字所能取到的最大子序列的大小，
    因此，以第一个数字构成的长度为 1 的序列为初始条件，构建DP方程即可
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