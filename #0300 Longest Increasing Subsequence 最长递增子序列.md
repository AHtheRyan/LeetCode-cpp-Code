### 最长递增子序列
### Longest Increasing Subsequence

> 给你一个整数数组 `nums`，找到其中最长严格递增子序列的长度。  
> **子序列**是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，`[3,6,2,7]` 是数组 `[0,3,1,6,2,2,7]` 的子序列。  

> Given an integer array `nums`, return the length of the longest strictly increasing subsequence.  
> A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.  

----------

#### I 动态规划

根据题意容易知道，每个位置能否和前面的数字组成递增序列取决于前面的数字是否小于该数字以及前面的数字所能取到的最大子序列的大小，  
因此，以第一个数字构成的长度为 `1` 的序列为初始条件，构建DP方程即可  

```cpp
int lengthOfLIS(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    for (int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    return *max_element(dp.begin(), dp.end());
}
```

#### II 贪心 + 二分

建立一个数组，记录潜在的最长的子序列，对于任意位置的数字，我们可以这样分析：  
- 如果其比目前最长的子序列的最后一个要长，则其会使得最长子序列的长度增加  
- 否则，其不会对最长子序列的长度受影响，但是其可能对之后的数字的大小判断产生影响，因此可以将其替换到目前的子序列中比其大的第一个元素的位置  

遍历完整个数组，即可得到最长子序列的大小  

```cpp
int lengthOfLIS(vector<int>& nums) 
{
    int size = nums.size();
    vector<int> ret;
    ret.push_back(nums[0]);
    for(int i = 1; i < size; ++i)
    {
        auto it = lower_bound(ret.begin(), ret.end(), nums[i]);
        if(it == ret.end())
            ret.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return ret.size();
}
```
