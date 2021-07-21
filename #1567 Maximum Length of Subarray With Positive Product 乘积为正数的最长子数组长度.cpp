/*
    we can naturally think about solving the problem with Dynamic Pogramming if we have done #53 and #152,
    obviouly there is relationship between negative and positive number in the array, so we can create two variables to store numbers of positive and negtive number, here are the solution:
    1. current number is 0:
       no matte what thr number before current index is, the counting will stop here and we should set two variables into 0
    2. current number is positive:
        2.1 if positive number count is not 0, we can add 1 to it, because pos × pos = pos
        2.2 if negative number count is not 0, we can add 1 to it, because neg × pos = neg
        2.3 if positive number count is 0, we can add 1 to it, because postive number count is already set to 0
        2.4 if negative number count is 0, the negative number count stays still
    3. current number is negative:
        3.1 if positive number count is not 0, we can add 1 to negative number count, because pos × neg = neg
        3.2 if negative number count is not 0, we can add 1 to positive number count, because neg × neg = pos
        3.3 if positive number count is 0, then negative number count = positive number count + 1, because postive number count is already set to 0
        3.4 if negative number count is 0, then posative number count stays 0
    E.G. in array [2, -2, -3, -4, 3, 5， -1], initial pos_num_count = 1 and neg_num_cunt = 0 because the first number is 2, according to the rules:
    at position -2, pos_num_count = 0, neg_num_count = 1
    at position -3, pos_num_count = 2, neg_num_count = 1
    at position -4, pos_num_count = 2, neg_num_count = 3
    at position  3, pos_num_count = 3, neg_num_count = 4
    at position  5, pos_num_count = 4, neg_num_count = 5
    at position -1, pos_num_count = 6, neg_num_count = 5
*/
/*
    考虑形成正数的最长乘积，如果做完 #53 最大子序和，#152乘积最大子数组，自然而然会想到使用动态规划的方式解决，
    显然，题目中正负数之间存在关系，只是在负数转化为正数和正数转化为负数的几个位置，对于变量的处理有难度，那我们可以创建两个变量分别计数正数和负数的数目，下面为解决办法：
    1. 考虑当前的数字为0
       因为当前数字为0，所以不管前面的数字是多少，此处计数都会终止，正数和负数的长度计数都归零
    2. 考虑当前数字为正数
        2.1 如果正数长度计数不为0，那么此时可以给正数的长度计数+1，因为正数×正数=正数
        2.2 如果负数长度计数不为0，那么此时可以给负数的长度计数+1，因为负数×正数=负数
        2.3 如果正数长度计数为0，那么此时可以给正数的长度计数+1，因为根据 1 ，计数归零（可归入2.1的情况）
        2.4 如果负数长度计数为0，那么此时负数的长度为0不变
    3. 考虑当前数字为负数
        3.1 如果正数长度计数不为0，那么此时负数的长度计数 = 正数的长度计数 + 1，因为正数×负数=负数
        3.2 如果负数长度计数不为0，那么此时正数的长度计数 = 负数的长度计数 + 1，因为负数×负数=正数
        3.3 如果正数长度计数为0，那么此时负数的长度计数 = 正数的长度计数 + 1，因为根据 1 ，计数归零（可归入3.1的情况）
        3.4 如果负数长度计数为0，那么此时正数的长度为0不变
    化简后共有 7 种情况
    例如，在数组[2, -2, -3, -4, 3, 5， -1]中，因为第一个数字为2，所以初始值正数计数=1，负数计数=0，根据规则：
    在-2位置：正数计数 = 0，负数计数 = 1
    在-3位置：正数计数 = 2，负数计数 = 1
    在-4位置：正数计数 = 2，负数计数 = 3
    在 3位置：正数计数 = 3，负数计数 = 4
    在 5位置：正数计数 = 4，负数计数 = 5
    在-1位置：正数计数 = 6，负数计数 = 5
    所以可以返回最大结果6
*/

int getMaxLen(vector<int>& nums)
{
    int size = nums.size();
    int negcount = 0;
    int poscount = 0;

    if (nums[0] > 0)
        ++poscount;
    if (nums[0] < 0)
        ++negcount;

    int maxlen = poscount;
    for (int i = 1; i < size; ++i)
    {
        int preneg = negcount;
        int prepos = poscount;
        if (nums[i] > 0)
        {
            poscount = poscount + 1;
            negcount = (preneg == 0) ? 0 : (preneg + 1);
        }
        if (nums[i] < 0)
        {
            negcount = prepos + 1;
            poscount = (preneg == 0) ? 0 : (preneg + 1);
        }
        if (nums[i] == 0)
            poscount = negcount = 0;
        maxlen = poscount > maxlen ? poscount : maxlen;
    }

    return maxlen;
}