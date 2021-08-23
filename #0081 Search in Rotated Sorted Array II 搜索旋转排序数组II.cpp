/*
    由于是查找，所以直接进行二分即可，
    1. 如果 mid 指针对应的数字为目标值，则直接返回 true
    2. 如果最右侧指针对应的数字等于 mid 指针对应的数字，则可以通过将右指针左移一位来重置判断条件
    3. 如果 mid 指针对应的值小于 right 指针对应的值
        3.1 如果 mid 指针对应的值小于目标值，并且 right 指针对应的值大于目标值，说明本段数组是递增的，则在本段内可以采用二分查找
        3.2 如果不满足3.1，则说明本段数组不是递增的，则对另一分段采用二分查找
    4. 如果 mid 指针对应的值大于 right 指针对应的值
        4.1 如果 mid 指针对应的值大于目标值，并且 left 指针对应的值小于目标值，说明本段数组是递增的，则在本段内可以采用二分查找
        4.2 如果不满足4.1，则说明本段数组不是递增的，则对另一分段采用二分查找
*/ 

bool search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[right] == nums[mid])
            --right;
        else if (nums[mid] < nums[right])
        {
            if (nums[mid] < target && nums[right] >= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            if (nums[mid] > target && nums[left] <= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return false;
}