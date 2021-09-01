/*
    题目本身不难，直接设置left、mid、right三个指针，排序后遍历即可
    难点在于机器性能有限的情况下如何节约计算时间：
    1. left移动的过程中，如果 left+1 和 left 下标的数字一样，可以直接跳过，mid同理
    2. numsleft] + nums[mid] + nums[right]的值如果大于0，那么可以只 --right，如果mid == right 或者和小于0，则直接循环结束
    3. 上面过程的right可以保留，因为移动 mid 指针必然使该数字增大，所以只要从最小可能的 right 计算即可
    这样就就可以节约整体的运行时间
*/

vector<vector<int>> threeSum(vector<int>& nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    for (int left = 0; left < size - 2; ++left)
    {
        if (left > 0 && nums[left] == nums[left - 1])
            continue;
        int target = -nums[left];
        int right = size - 1;
        for (int mid = left + 1; mid < size - 1; ++mid)
        {
            if (mid > left + 1 && nums[mid] == nums[mid - 1])
                continue;
            while (mid < right && nums[mid] + nums[right] > target)
                --right;
            if (mid == right)
                break;
            if (nums[mid] + nums[right] == target)
                ret.push_back({ nums[left], nums[mid], nums[right] });
        }
    }
    return ret;
}
