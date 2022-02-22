### 在排序数组汇总查找元素的第一个和最后一个位置
### Find First and Last Position of Element in Sorted Array

> 给定一个按照升序排列的整数数组 `nums`，和一个目标值 `target`。找出给定目标值在数组中的开始位置和结束位置。  
> 如果数组中不存在目标值 `target`，返回 `[-1, -1]`。  

> Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.  
> If `target` is not found in the array, return `[-1, -1]`.  
> You must write an algorithm with `O(log n)` runtime complexity.  

----------

#### I 二分法

此题可以看做是 c++ 中 upper_bound 和 lower_bound 两个函数的实现过程，  
由于是寻找特定的值，所以显然二分法可以实现 o(log n)的时间，  
直接利用二分法进行查找即可  

```cpp
vector<int> searchRange(vector<int>& nums, int target) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int ret1 = -1;
    int ret2 = -1;
    while(left <= right && ret1 == -1)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] == target && (mid == 0 || nums[mid - 1] != target))
            ret1 = mid;
        else
            right = mid - 1;
    }
    if(ret1 == -1)
        return {-1, -1};
    left = ret1;
    right = n - 1;
    while(left <= right && ret2 == -1)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target && (mid == n - 1 || nums[mid + 1] != target))
            ret2 = mid;
        else
            left = mid + 1;
    }
    return {ret1, ret2};
}
```
