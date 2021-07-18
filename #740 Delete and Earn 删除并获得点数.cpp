/*
    every scores gotten from the numbers will be affected by two factors: the number itself and the times the number appears,
    E.G. in array [2, 2, 3, 3, 3, 4], choose number "3" actually means getting every "3" in the array,
    which means we can transfer the array into another form: [(2, 2), (3, 3), (4, 1)], in which the 1st number means the number itself, and the 2nd number means the times the number appears,
    and the multipication of the pair shows a number's real value,
    we can further transfer it into[4, 9, 4], where the three numbers correspond to the  numbers 2, 3, 4,
    after each value is chosen, the adjacent value is deleted directly, so we can convert it into two corresponding arrays:
    [0, 1, 2, 3, 4] which represents the number itself,
    [0, 0, 4, 9, 4] which represents the scores we can get after choose the number,
    according to the rules, if we choose a certain number, we cannot choose the numbers before and after it,
    thus the question can be transformed into the "#198 House Robber" problem, which can be solved by dynamic programming.
*/
/*
    每一个数字相关的分数都有两个因素影响：数字的值和该数字出现的次数，
    例如在[2, 2, 3, 3, 3, 4]中，选择 “3” 实质上就是把每个3都获得，
    这也就意味着，此数组实际上可以看做这样的二元数组：[(2, 2), (3, 3), (4, 1)]，每一对数字前者代表数字的值，后者代表数字出现的次数，数字实际所包含的价值是两者相乘，
    进一步转化为[4, 9, 4]，其中，三个数字分别对应2,3,4三个数字“基底”，且每个值取完之后，和他相邻的值就直接删除了，为了计算方便，我们将其转化为两个对应的数组：
    [0, 1, 2, 3, 4]表示数字本身
    [0, 0, 4, 9, 4]表示选择该数字得到的分数
    根据规则，选择某一个数字就不能选择他前后的数字了，这里可以转化为《#198 打家劫舍》问题，使用动态规划解决
*/

int deleteAndEarn(vector<int>& nums)
{
    int size = nums.size();
    int max = 0;
    for (int val : nums)
        max = val > max ? val : max;        
    vector<int> number(max + 1);
    for (int i = 0; i < size; ++i)
        ++number[nums[i]];
    vector<int> dp(max + 1);
    dp[1] = number[1] * 1;
    for (int j = 2; j < number.size(); ++j)
    {
        int cur = dp[j - 2] + number[j] * j;
        dp[j] = dp[j - 1] > cur ? dp[j - 1] : cur;
    }
    return dp[max];
}

