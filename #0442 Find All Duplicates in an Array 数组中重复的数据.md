### 数组中重复的数据
### Find All Duplicates in an Array

> 给你一个长度为 `n` 的整数数组 `nums`，其中 `nums` 的所有整数都在范围 `[1, n]` 内，且每个整数出现**一次**或**两次**。请你找出所有出现**两次**的整数，并以数组形式返回。

> Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.  

----------

#### I 原地哈希

由于数组大小与数字范围相同，可以利用原地哈希节约空间，我们将出现的数字 `cur` 作为下标，将该下标对应的位置的数字 `k` 置为负数作为遇到一次出现的数字  
当第二次遇见出现的数字 `cur`，查找对应位置可发现该位置已经变成了负数，证明此次是第二次遇到，则记录改数字即可  

```cpp
vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> ret;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        int cur = abs(nums[i]) - 1;
        if(nums[cur] > 0)
            nums[cur] = -nums[cur];
        else
            ret.emplace_back(abs(nums[i]));
    }
    return ret;
}
```
