### 搜索旋转排序数组II
### Search in Rotated Sorted Array II

> 已知存在一个按非降序排列的整数数组 `nums`，数组中的值不必互不相同。  
> 在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了**旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标**从0开始**计数）。例如，`[0,1,2,4,4,4,5,6,6,7]` 在下标 `5` 处经旋转后可能变为 `[4,5,6,6,7,0,1,2,4,4]`。  
> 给你**旋转后**的数组 `nums` 和一个整数 `target`，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 `nums` 中存在这个目标值 `target`，则返回 `true`，否则返回 `false`。  

> There is an integer array `nums` sorted in non-decreasing order (not necessarily with **distinct** values).  
> Before being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,4,4,5,6,6,7]` might be rotated at pivot index `5` and become `[4,5,6,6,7,0,1,2,4,4]`.  
> Given the array `nums` **after** the rotation and an integer `target`, return *`true` if `target` is in `nums`, or `false` if it is not in `nums`*.  

----------

#### I 二分查找

由于是查找，所以直接进行二分即可，  
1. 如果 `mid` 指针对应的数字为目标值，则直接返回 `true`  
2. 如果最右侧指针对应的数字等于 `mid` 指针对应的数字，则可以通过将右指针左移一位来重置判断条件  
3. 如果 `mid` 指针对应的值小于 `right` 指针对应的值  
    3.1 如果 `mid` 指针对应的值小于目标值，并且 `right` 指针对应的值大于目标值，说明本段数组是递增的，则在本段内可以采用二分查找  
    3.2 如果不满足3.1，则说明本段数组不是递增的，则对另一分段采用二分查找  
4. 如果 `mid` 指针对应的值大于 `right` 指针对应的值  
    4.1 如果 `mid` 指针对应的值大于目标值，并且 `left` 指针对应的值小于目标值，说明本段数组是递增的，则在本段内可以采用二分查找  
    4.2 如果不满足4.1，则说明本段数组不是递增的，则对另一分段采用二分查找  

```cpp
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
```
