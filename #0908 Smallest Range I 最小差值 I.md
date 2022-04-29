### 最小差值
### Smallest Range

> 给你一个整数数组 `nums`，和一个整数 `k`。  
> 在一个操作中，您可以选择 `0 <= i < nums.length` 的任何索引 `i`。将 `nums[i]` 改为 `nums[i] + x`，其中 `x` 是一个范围为 `[-k, k]` 的整数。对于每个索引 `i`，最多**只能**应用**一次**此操作。  
> `nums` 的**分数**是 `nums` 中最大和最小元素的差值。   
> *在对 `nums` 中的每个索引最多应用一次上述操作后，返回 `nums` 的最低**分数***。  

> You are given an integer array `nums` and an integer `k`.  
> In one operation, you can choose any index `i` where `0 <= i < nums.length` and change `nums[i]` to `nums[i] + x` where `x` is an integer from the range `[-k, k]`. You can apply this operation **at most once** for each index `i`.  
> The **score** of `nums` is the difference between the maximum and minimum elements in `nums`.  
> Return *the minimum **score** of `nums` after applying the mentioned operation at most once for each index in it*.  

----------

#### I 一次遍历

通过一次遍历找到最大和最小的元素进行比较：  
- 如果两个元素的差值小于 `2k`，说明可以处理之后使得两个元素差值小于 `0`，则直接返回 `0`  
- 否则说明两个元素只差减去 `2k` 仍然大于 `0`，则返回 `差值 - 2k` 即可  

```cpp
int smallestRangeI(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxnum = INT_MIN;
    int minnum = INT_MAX;
    for(auto& num : nums)
    {
        maxnum = max(maxnum, num);
        minnum = min(minnum, num);
    }
    int delta = maxnum - minnum;
    return delta <= k * 2 ? 0 : delta - k * 2;
}
```
