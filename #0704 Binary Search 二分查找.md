### 二分查找
### Binary Search

> 给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target`，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。

> Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If target exists, then return its index. Otherwise, return `-1`.  
> You must write an algorithm with `O(log n)` runtime complexity.  

----------

#### I 二分法

非常简单基础的二分查找题目  
由于数组本身升序排列，可以直接通过二分查找解决问题

```cpp
int search(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;    
    }
    return -1;
}
```
