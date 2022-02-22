### 搜索插入位置
### Search Insert Position

> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。  
> 请必须使用时间复杂度为 `O(log n)` 的算法。  

> Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.  
> You must write an algorithm with `O(log n)` runtime complexity.  

----------

#### I 二分法

简单二分题，注意边界条件即可  

```cpp
int searchInsert(vector<int>& nums, int target) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int index = 0;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
        {
            index = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            index = mid + 1;
        }
    }
    return index;
}
```
