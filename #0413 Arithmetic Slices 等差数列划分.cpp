/*
    analyse the array with 3 numbers as a unit, if three numbers can form an arithmetic sequence, 
    then the numbers of arithmetic sequence in the position = the numbers of arithmetic sequence in the previous positoin + 1,
    add up all the possibilities and we get the result
*/
/*
    以三个数字为单位分析，如果三个数字能组成等差数列，那么该位置的等差数列数目就是前一位置的等差数列数目 + 1，
    最后将所有位置能形成的等差数列数目加在一起即可
*/

int numberOfArithmeticSlices(vector<int>& nums)
{
    int size = nums.size();
    if (size <= 1)
        return 0;
    vector<int> dp(size);
    dp[0] = dp[1] = 0;
    for (int i = 2; i < size; ++i)
        if (nums[i] + nums[i - 2] == 2 * nums[i - 1])
            dp[i] = dp[i - 1] + 1;
    return accumulate(dp.begin(), dp.end(), 0);
}
