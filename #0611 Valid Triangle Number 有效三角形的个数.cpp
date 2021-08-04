/*
    三角形的成立条件是两边之和小于第三边，
    因此，可以采用双指针，先从左边锁定两个较小的边，然后利用二分查找寻找满足条件的最大的边的位置，
    找到该位置后，可以按照该位置和两条边中较大的边的下标距离确定所满足条件的三角形个数，
    将确定的三角形个数累加即可
*/ 

int triangleNumber(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int ret = 0;
    for (int i = 0; i < size - 2; ++i)
    {
        for (int j = i + 1; j < size - 1; ++j)
        {
            auto it = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]);
            if (it != nums.end() && it - nums.begin() > j)
                ret += it - nums.begin() - j - 1;
            else if (it == nums.end())
                ret += size - j - 1;
        }
    }
    return ret;
}