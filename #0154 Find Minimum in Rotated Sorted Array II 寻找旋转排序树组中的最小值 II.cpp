/*
    此题类似于 #81 搜索旋转排序树组II，这里同样采用二分法解决问题，
    对 mid 指针位置的数字进行检查
    1. 如果该位置与最右侧相同，则将最右侧的指针 right 减一
    2. 如果 mid 指针对应的数字大于 right 指针对应的数字，则说明右侧该段序列存在递减序列，将 left 指针加一后继续进行二分查找
    3. 如果 mid 指针对应的数字小于 right 指针对应的数字，则说明右侧该段序列为递增序列，将 right 指针减一后继续进行二分查找
*/ 

int findMin(vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[right])
            --right;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}