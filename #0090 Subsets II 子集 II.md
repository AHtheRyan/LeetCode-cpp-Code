### 子集 II
### Subsets II

> 给你一个整数数组 `nums`，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。  
> 解集**不能**包含重复的子集。返回的解集中，子集可以按**任意顺序**排列。  

> Given an integer array `nums` that may contain duplicates, return *all possible subsets (the power set)*.  
> The solution set **must not** contain duplicate subsets. Return the solution in **any order**.  

---------- 

#### I 回溯

回溯过程比较简单，主要需要考虑去重问题，需要去重的数字考虑如下：  
如果数字本身与列表中前一个数字相同，则可能改数字需要去重，此时  
- 如果前一个数字被取用过，则当前数字加入可形成一个更大的数组，故可以继续取用  
- 如果前一个数字未被取用，则说明当前数字已经被取用过了且不用考虑重复的情况，故舍弃  

按照上述规律作为规则进行判断即可  

```cpp
class Solution 
{
private:
    vector<vector<int>> ret;
    vector<int> cur;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        backtrack(false, nums, 0);
        return ret;
    }

    void backtrack(bool preflag, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            ret.push_back(cur);
            return;
        }
        backtrack(false, nums, index + 1);
        if(index > 0 && !preflag && nums[index] == nums[index - 1])
            return;
        cur.emplace_back(nums[index]);
        backtrack(true, nums, index + 1);
        cur.pop_back();
    }
};
```

#### II 迭代

去重规则见上  

```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    vector<int> cur;
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int mask = 0; mask < (1 << n); ++mask)
    {
        cur.clear();
        bool flag = true;
        for(int i = 0; i < n; ++i)
        {
            if(mask & (1 << i))
            {
                if(i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1])
                {
                    flag = false;
                    break;
                }
                cur.emplace_back(nums[i]);
            }
        }
        if(flag)
            ret.push_back(cur);
    }
    return ret;
}
```
