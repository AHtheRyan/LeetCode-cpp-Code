/*
    换皮排序题，由于只有0, 1, 2 三个数字，我们可以从左到右遍历数组，同时对左右两个端点设置指针
    1. 如果遍历位置的值为 2，将其与右端点换位，将右端点指针减一
    2. 如果遍历位置的值为 0，将其与左端点换位，将左端点和便利位置的指针都加一
    3. 如果便利位置的值为 1，则跳过该位置
    便利结束后即可得到结果
*/ 

void sortColors(vector<int>& nums)
{
    int right = nums.size() - 1;
    int left = 0;
    int pos = 0;
    while (pos <= right)
    {
        if (nums[pos] == 2)
            swap(nums[pos], nums[right--]);
        else if (nums[pos] == 0)
            swap(nums[pos++], nums[left++]);
        else
            ++pos;
    }
}