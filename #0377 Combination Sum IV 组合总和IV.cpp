/*
    对于nums = [1, 2, 3]和任意target，我们可以按顺序分析数字找出规律：
    对于数字 1，组合为
        1
        结果为 1
    对于数字 2，组合为
        1, 1
        2
        结果为2
    对于数字 3，组合为
        1, 1, 1
        1, 2
        2, 1
        3
        结果为4
    对于数字 4，组合为
        1, 1, 1, 1
        1, 1, 2
        1, 2, 1
        1, 3
        2, 1, 1
        2, 2
        3, 1
        结果为7
    以此类推，可见我们可以分别以nums中的数字作为基底考虑情况（上面例子中的第一列），那么后面几列就变成了之前讨论过的情况
    比如对于数字 4，我们考虑 1 为基底，那么后面的情况就是数字 3 的 4 种情况，考虑 2 为基底，那么后面就是数字 2 的 2 种情况，
    可由此得出DP递推规律
*/

int combinationSum4(vector<int>& nums, int target)
{
    int size = nums.size();
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int j = 1; j <= target; ++j)
        for (int i = 0; i < size; ++i)
            if (j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])
                dp[j] += dp[j - nums[i]];
    return dp[target];
}