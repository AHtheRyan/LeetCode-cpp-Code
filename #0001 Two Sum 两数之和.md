### 两数之和
### Two Sum

> 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那**两个**整数，并返回它们的数组下标。  
> 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。  
> 你可以按任意顺序返回答案。  

> Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.  
> You may assume that each input would have exactly one solution, and you may not use the same element twice.  
> You can return the answer in any order.  

----------

#### I 哈希表

使用哈希表存储每个首次出现的数字，储存的内容为该数字及其在原数组中的下标，即哈希表的格式为：`(出现的数字x，该数字x的下标)`  
从零开始遍历原数组，每一次都寻找 `target-当前数字` 所表示的数字是否存在，如某一个数字是 **3**，目标是 **9**，那么我们就寻找数字 **6** 是否存在于哈希表中：  
1. 不存在，那么将数字 `3` 和其下标 `x` 存储在哈希表中  
2. 存在，那么直接返回当前数字 `3` 的下标和存在哈希表里的那个数字的下标 `y`  

```cpp
vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> hash;
    int size = nums.size();
    for(int i = 0; i < size; ++i)
    {
        if(hash.find(target - nums[i]) == hash.end())
            hash[nums[i]] = i;
        else
            return {hash[target - nums[i]], i};
    }
    return {};
}
```
