### 增量元素之间的最大差值
### Maximum Difference Between Increasing Elements

> 给你一个下标从 **0** 开始的整数数组 `nums`，该数组的大小为 `n`，请你计算 `nums[j] - nums[i]` 能求得的 **最大差值**，其中 `0 <= i < j < n` 且 `nums[i] < nums[j]`。  
> 返回 **最大差值**。如果不存在满足要求的 `i` 和 `j` ，返回 `-1`。  

> Given a **0-indexed** integer array `nums` of size `n`, find the **maximum difference** between `nums[i]` and `nums[j]` (i.e., `nums[j] - nums[i]`), such that `0 <= i < j < n` and `nums[i] < nums[j]`.  
> Return *the **maximum difference***. If no such `i` and `j` exists, return `-1`.  

----------

#### I 一次遍历

遍历数组，使用 `nums[j] - nums[i]`，如果值变大，则更新，如果 `nums[j]` 变小，则比较 `nums[i]` 和 `nums[j]`，取较小的数字的下标作为新的 `i`，遍历至数组最后即可  

```cpp
int maximumDifference(vector<int>& nums) 
{
    int left = 0;
    int mov = left + 1;
    int ret = -1;
    while(mov < nums.size())
    {
        if(nums[mov] - nums[mov - 1] > 0)
            ret = max(nums[mov] - nums[left], ret);
        else
            left = nums[left] < nums[mov] ? left : mov;
        ++mov;
    }
    return ret;
}
```
