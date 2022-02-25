### 缺失的第一个正数
### First Missing Positive

> 给你一个未排序的整数数组 `nums`，请你找出其中没有出现的最小的正整数。  
> 请你实现时间复杂度为 `O(n)` 并且只使用常数级别额外空间的解决方案。  

> Given an unsorted integer array `nums`, return the smallest missing positive integer.  
> You must implement an algorithm that runs in `O(n)` time and uses constant extra space.  

----------

#### I 原地哈希

可以将数组本身视作哈希表，以下标作为数字判断源，以指向的数字的正负表示数字是否出现  

```cpp
int firstMissingPositive(vector<int>& nums) 
{
    int n = nums.size();
    for(auto& num : nums)
        if(num <= 0)
            num = n + 1;
    for(int i = 0; i < n; ++i)
    {
        int num = abs(nums[i]);
        if(num <= n)
            nums[num - 1] = -abs(nums[num - 1]);
    }
    for(int i = 0; i < n; ++i)
        if(nums[i] > 0)
            return i + 1;
    return n + 1;
}
```
