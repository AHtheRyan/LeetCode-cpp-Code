### 最长和谐子序列
### Longest Harmonious Subsequence

> 和谐数组是指一个数组里元素的最大值和最小值之间的差别 **正好是** `1`。  
> 现在，给你一个整数数组 `nums`，请你在所有可能的子序列中找到最长的和谐子序列的长度。  
> 数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。  

> We define a harmonious array as an array where the difference between its maximum value and its minimum value is **exactly** `1`.  
> Given an integer array `nums`, return *the length of its longest harmonious subsequence among all its possible subsequences*.  
> A **subsequence** of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.  

----------

#### I 哈希表

根据题意，最终寻找的是差值为 `1` 的出现次数最多的两个数字  
涉及到出现次数，最佳方法为利用哈希表，可以遍历一次并进行记录  
之后对哈希表每个元素及比其大 `1` 的元素进行分析即可

```cpp
int findLHS(vector<int>& nums) 
{
    unordered_map<int, int> cnt;
    for(auto num : nums)
        ++cnt[num];
    int ret = 0;
    for(auto [key, val] : cnt)
        if(cnt.count(key + 1))
            ret = max(ret, val + cnt[key + 1]);
    return ret;
}
```
