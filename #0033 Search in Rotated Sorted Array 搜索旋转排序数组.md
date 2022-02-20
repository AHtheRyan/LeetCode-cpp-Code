### 搜索旋转排序数组
### Search in Rotated Sorted Array

> 整数数组 `nums` 按升序排列，数组中的值 **互不相同**。  
> 在传递给函数之前，`nums`在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了**旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标**从 0 开始**计数）。例如， `[0,1,2,4,5,6,7]` 在下标 `3` 处经旋转后可能变为 `[4,5,6,7,0,1,2]`。  
> 给你**旋转后**的数组 nums 和一个整数 `target`，如果 `nums` 中存在这个目标值 `target`，则返回它的下标，否则返回 `-1`。  

> There is an integer array `nums` sorted in ascending order (with **distinct** values).  
> Prior to being passed to your function, `nums` is **possibly rotated** at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.  
> Given the `array` nums **after** the possible rotation and an integer `target`, return *the index of `target` if it is in `nums`, or `-1` if it is not in `nums`*.  
> You must write an algorithm with `O(log n)` runtime complexity.  

----------

#### I 二分查找

查找类题目要求时间为 `o(log n)`，必然为二分法  
这里二分注意考虑多种情况即可

```cpp
int search(vector<int>& nums, int target) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
        {
            if(nums[right] <= nums[mid] && nums[left] > target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        else if(nums[mid] < target)
        {
            if(nums[left] >= nums[mid] && nums[right] < target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if(nums[mid] == target)
            return mid;
    }
    return -1;
}
```
