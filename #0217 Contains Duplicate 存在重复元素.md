### 存在重复元素
### Contains Duplicate

> 给你一个整数数组 `nums`。如果任一值在数组中出现**至少两次**，返回 `true`；如果数组中每个元素互不相同，返回 `false`。  

> Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.  

----------

#### I 排序

排序后，相同元素会相邻，可直接进行判断

```cpp
bool containsDuplicate(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); ++i)
        if(nums[i] == nums[i - 1])
            return true;
    return false;
}
```

#### II 哈希表

记录每个遇到的元素，如果遇到记录过的元素则返回 `true`，否则返回 `false`  

```cpp
bool containsDuplicate(vector<int>& nums) 
{
    unordered_set<int> st;
    for(auto& num : nums)
    {
        if(st.count(num))
            return true;
        st.insert(num);
    }
    return false;
}
```
