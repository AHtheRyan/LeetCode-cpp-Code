/*
    according to the question, traverse the array in order, we can get different max_sum_subarray from every position
    E.G. in array [-2, 1, -3, 4, -1, 2, 1, -5, 4],
    max_subarray of index '0' is the value '-2',
    pmax_subarray of index '1' comes from 2 conditions: 1. the value '1' itself; 2. previous max_subarray plus current value, obviously the bigger one is the result,
    thus, the value of the max_subarray is the larger one between the value of the index value itself and the previous previous max_subarray plus the index value,
    so we can traverse the array and get max_subarray on each position(index), and return the maximum number of them.
*/
/*
    根据题目要求，按顺序遍历数组，从下标0开始到下标最大的位置，每个位置都有对应的最大子序列和，
    例如，在数列[-2, 1, -3, 4, -1, 2, 1, -5, 4]中，
    下标 “0” 对应的最大子序和就是 “-2”，
    下标 “1” 对应的则有两种可能：1. 只取本身，即 “1”； 2.前面的最大子序和加上当前数字，即 “-1”，显然，取二者最大值即可，后续同理，
    即对每个下标而言，截止到该位置的最大子序和的值是单独取该位置的值或者前面的最大子序和加上该位置的值中较大的那个，
    因此，可以遍历一遍数组，得到每个位置的最大子序和，取其中的最大值。
*/

//v1.0
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    dp[0] = nums[0];
    for (int i = 1; i < size; ++i)
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
    return *max_element(dp.begin(), dp.end());
}

//v1.1
//remove vector dp, use a single variable to store the result, which saves the memory
//取消了dp数组的构建，使用一个单独的变量存储，节约了空间的使用
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    int max = nums[0];
    int cur = max;
    for (int i = 1; i < size; ++i)
    {
        cur = nums[i] + cur > nums[i] ? nums[i] + cur : nums[i];
        max = cur > max ? cur : max;
    }
    return max;
}

