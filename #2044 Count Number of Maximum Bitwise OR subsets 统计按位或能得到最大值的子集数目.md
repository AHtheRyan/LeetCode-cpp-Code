### 统计按位或能得到最大值的子集数目
### Count Number of Maximum Bitwise-OR Subsets

> 给你一个整数数组 `nums`，请你找出 `nums` 子集**按位或**可能得到的**最大值**，并返按位或能得到最大值的**不同非空子集的数目**。  
> 如果数组 `a` 可以由数组 `b` 删除一些元素（或不删除）得到，则认为数组 `a` 是数组 `b` 的一个**子集**。如果选中的元素下标位置不一样，则认为两个子集**不同**。  
> 对数组 `a` 执行**按位或**，结果等于 `a[0] OR a[1] OR ... OR a[a.length - 1]`（下标从**0**开始）。  

> Given an integer array `nums`, find the **maximum** possible **bitwise OR** of a subset of `nums` and return *the **number of different non-empty subsets** with the maximum bitwise OR*.  
> An array `a` is a subset of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`. Two subsets are considered **different** if the indices of the elements chosen are different.  
> The bitwise OR of an array `a` is equal to `a[0] OR a[1] OR ... OR a[a.length - 1]`(**0-indexed**).  

----------

#### I 状态压缩位运算

根据题意，共有的组合数量为 `2^n`，其中，`n` 为数组长度，  
这样就可以用位运算来代替选取每个位置的状态，其中 `1` 表示选取，`0`表示不选取，  
进行迭代判断即可  

```cpp
int countMaxOrSubsets(vector<int>& nums) 
{
    int cnt = 0;
    int max = 0;
    for(auto& num : nums)
        max |= num;
    int n = nums.size();
    int stateNum = 1 << n;
    for(int i = 1; i < stateNum; ++i)
    {
        int cur = 0;
        for(int j = 0; j < n; ++j)
            if(((i >> j) & 1) == 1)
                cur |= nums[j];
        if(cur == max)
            ++cnt;
    }
    return cnt;
}
```

#### II DFS

这种可取可不取的问题，可以利用DFS来解决，先求出最大值，然后每次进行DFS运算时，考虑两种情况：  
1. 不取当前数进行按位或运算   
2. 取当前数进行按位或运算  

这样就可以实现每种情况都考虑  

```cpp
class Solution 
{
private:
    int max;
    int cnt;
    vector<int> nums;

public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        this->nums = nums;
        this->max = 0;
        for(auto& num : nums)
            max |= num;
        this->cnt = 0;
        backtrack(0, 0);
        return cnt;
    }

    void backtrack(int cur, int index)
    {
        if(index == nums.size())
        {
            if(cur == max)
                ++cnt;
            return;
        }
        backtrack(cur, index + 1);
        backtrack(cur | nums[index], index + 1);
    }
};
```
