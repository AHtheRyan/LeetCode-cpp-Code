### 递增的三元子序列
### Increasing Triplet Subsequence

> 给你一个整数数组 `nums`，判断这个数组中是否存在长度为 `3` 的递增子序列。  
> 如果存在这样的三元组下标 `(i, j, k)` 且满足 `i < j < k`，使得 `nums[i] < nums[j] < nums[k]`，返回 `true`；否则，返回 `false`。  

> Given an integer array `nums`, return `true` *if there exists a triple of indices `(i, j, k)` such that `i < j < k` and `nums[i] < nums[j] < nums[k]`*. If no such indices exists, return `false`.  

----------

#### I 贪心

本问题贪心可解，  
遍历数组，不断记录并更新最小值和第二小的值，  
遍历到某一数字大于当前确定的第二小的值之后，则必然存在递增三元子序列  

```cpp
bool increasingTriplet(vector<int>& nums) 
{
    int first = INT_MAX;
    int second = INT_MAX;
    for(auto num : nums)
    {
        if(num <= first)
            first = num;
        else if(num <= second)
            second = num;
        else
            return true;
    }
    return false;
}
```
