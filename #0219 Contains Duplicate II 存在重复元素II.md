### 存在重复元素II
### Contains Duplicate II

> 给你一个整数数组 `nums` 和一个整数 `k`，判断数组中是否存在两个 不同的索引 `i` 和 `j`，满足 `nums[i] == nums[j]` 且 `abs(i - j) <= k`。如果存在，返回 `true`；否则，返回 `false`。  

> Given an integer array `nums` and an integer `k`, return `true` if there are two **distinct indices** `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.  

----------

#### I 哈希表

利用哈希表记录每个元素的下标  
遍历数组，当遇到重复元素时，将记录的下标和当前下标进行减法运算，如果符合直接返回 `true`，否则可以更新下标继续遍历  

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(mp.count(nums[i]) == 0)
            mp[nums[i]] = i;
        else if(i - mp[nums[i]] <= k)
            return true;
        else
            mp[nums[i]] = i;
    }
    return false;
}
```
