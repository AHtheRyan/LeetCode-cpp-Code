/*
    最简单的双指针算法就是，两个指针分别从左往右和从右往左遍历，
    符合条件的序列一定为数组最大值右侧所有和数组最小值左侧所有数组的集合，
    也就是子数组中最左端的值一定比子数组最小值大，子数组中最右端的值一定比子数组最大值小
*/

int findUnsortedSubarray(vector<int>& nums)
{
    int size = nums.size();
    int maxn = INT_MIN;
    int minn = INT_MAX;
    int left = -1;
    int right = -1;
    for (int i = 0; i < size; ++i)
    {
        if (maxn > nums[i])
            right = i;
        else
            maxn = nums[i];
        if (minn < nums[size - 1 - i])
            left = size - 1 - i;
        else
            minn = nums[size - 1 - i];
    }
    return right == -1 ? 0 : right - left + 1;
}
