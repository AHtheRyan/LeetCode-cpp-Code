### 寻找峰值
### Find Peak Element

> 峰值元素是指其值严格大于左右相邻值的元素。  
> 给你一个整数数组 `nums`，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 **任何一个峰值** 所在位置即可。  
> 你可以假设 `nums[-1] = nums[n] = -∞` 。  
> 你必须实现时间复杂度为 `O(log n)` 的算法来解决此问题。  

> A peak element is an element that is strictly greater than its neighbors.  
> Given an integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.  
> You may imagine that `nums[-1] = nums[n] = -∞`.  
> You must write an algorithm that runs in `O(log n)` time.  

----------

#### I 二分查找

处于时间复杂度考虑，使用二分法是最好的选择，难点在于判断二分的条件，  
在题目中，我们首先利用传统二分，选择元素大于 `mid` 元素的一侧，  
接下来证明该侧一定有符合的值：
1. 如果该侧沿 `mid` 到边缘递增，则根据题意，`nums[-1] = nums[n] = -∞`，可以选择 `nums[0]` 或者 `nums[n - 1]` 作为峰值
2. 如果该侧不为递增，则由于已经有 `nums[mid + 1] > nums[mid]` 或 `nums[mid - 1] > nums[mid]`，必然存在一个峰值  

直接按此规则进行二分查找即可  

```cpp
int findPeakElement(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if((mid == nums.size() - 1 || nums[mid + 1] < nums[mid]) && (mid == 0 || nums[mid - 1] < nums[mid]))
            return mid;
        else if(nums[mid + 1] > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}
```
