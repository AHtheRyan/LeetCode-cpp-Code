### 最长定差子序列
### Longest Arithmetic Subsequence of Given Difference

> 给你一个整数数组 `arr` 和一个整数 `difference`，请你找出并返回 `arr` 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 `difference`。  
> **子序列** 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 `arr` 派生出来的序列。  

> Given an integer array `arr` and an integer `difference`, return the length of the longest subsequence in `arr` which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals `difference`.  
> A **subsequence** is a sequence that can be derived from `arr` by deleting some or no elements without changing the order of the remaining elements.  

----------

#### I 哈希表 + 动态规划

显然这是一道动态规划题目  
需要记录的点在于当到达某个位置时，该位置之前的子数组所形成的最长定差子序列的大小为多少  
显然，这个差值跟数字本身有关，跟下标无关，因此，我们可以利用每个位置的数字本身构建 `dp` 方程规律  
基于任意数字 `k`，其前面的最长定差子序列为 `dp[k - difference]`，则可以求出每个位置形成的定差子序列的大小  
再求出各子序列大小的最大值即可

```cpp
int longestSubsequence(vector<int>& arr, int difference) 
{
    int size = arr.size();
    unordered_map<int, int> dp;
    for(int i = 0; i < size; ++i)
        dp[arr[i]] = 1 + dp[arr[i] - difference];
    int max = 0;
    for(auto it : dp)
        max = it.second > max ? it.second : max;
    return max;
}
```
