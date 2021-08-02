/*
    做此题之前请先参阅 #152乘积最大子数组
    与该题类似，我们在这里需要考虑情况分为 3 类：
    1. 前一次形成的序列为递增
    2. 前一次形成的序列为递减
    3. 前一天序列不变化
    由于序列是摆动的，递减数组的增加需要看前一次的递增，递增的增加需要看前一次的递减，
    利用序列的第一个元素初始化构建DP数组即可
*/

int wiggleMaxLength(vector<int>& nums)
{
    int size = nums.size();
    int inc = 1;
    int dec = 1;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] - nums[i - 1] > 0)
            inc = max(dec + 1, inc);
        else if (nums[i] - nums[i - 1] < 0)
            dec = max(dec, inc + 1);
    }
    return max(inc, dec);
}