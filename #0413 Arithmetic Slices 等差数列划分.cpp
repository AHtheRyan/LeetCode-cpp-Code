/*
    analyse the array with 3 numbers as a unit, if three numbers can form an arithmetic sequence, 
    then the numbers of arithmetic sequence in the position = the numbers of arithmetic sequence in the previous positoin + 1,
    add up all the possibilities and we get the result
*/
/*
    ����������Ϊ��λ���������������������ɵȲ����У���ô��λ�õĵȲ�������Ŀ����ǰһλ�õĵȲ�������Ŀ + 1��
    �������λ�����γɵĵȲ�������Ŀ����һ�𼴿�
*/

int numberOfArithmeticSlices(vector<int>& nums)
{
    int size = nums.size();
    if (size <= 1)
        return 0;
    vector<int> dp(size);
    dp[0] = dp[1] = 0;
    for (int i = 2; i < size; ++i)
    {
        if (nums[i] + nums[i - 2] == 2 * nums[i - 1])
            dp[i] = dp[i - 1] + 1;
    }
    return accumulate(dp.begin(), dp.end(), 0);
}