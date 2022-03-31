### 子集
### Subsets

> 给你一个整数数组 `nums`，数组中的元素**互不相同**。返回该数组所有可能的子集（幂集）。  
> 解集**不能**包含重复的子集。你可以按**任意顺序**返回解集。  

> Given an integer array `nums` of **unique elements**, return *all possible subsets (the power set)*.  
> The solution set **must not** contain duplicate subsets. Return the solution in **any order**.  

----------

#### I 迭代

对 `nums` 数组中的每个数字进行处理，每次处理时，对已经处理好前面数字的数组进行复制，在复制好的数组中的每个集合加入当前元素，并拼接在原来的集合数组之后即可  

```cpp
vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> ret;
    ret.push_back({});
    for(int i = 0; i < nums.size(); ++i)
    {
        vector<vector<int>> tmp = ret;
        for(int j = 0; j < tmp.size(); ++j)
            tmp[j].emplace_back(nums[i]);
        for(auto& vec : tmp)
            ret.push_back(vec);
    }
    return ret;
}
```

#### II 回溯

与上述思路相同，每次遇到一个数字，考虑将其放入或不放入当前数组中，遍历完所有的数字后，便可获得最终的子集  

```cpp
class Solution 
{
private:
    vector<vector<int>> ret;
    vector<int> cur;

public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        backtrack(nums, 0);
        return ret;
    }

    void backtrack(vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ret.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        backtrack(nums, index + 1);
        cur.pop_back();
        backtrack(nums, index + 1);
    }
};
```
