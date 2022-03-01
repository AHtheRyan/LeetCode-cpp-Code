### 全排列 II
### Permutations II

> 给定一个可包含重复数字的序列 `nums`，***按任意顺序***返回所有不重复的全排列。  

> Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations ***in any order***.  

----------

#### I 回溯

与[全排列](../main/%230046%20Permutations%20%E5%85%A8%E6%8E%92%E5%88%97.md)思路相同  
这里原数组加入了重复元素，需要考虑重复问题  
我们可以设置新数组 `check`，通过记录每次选择的数字下标，保证每次选择的数字下标都是重复数字中出现的第一个，这样便可避免重复问题  

```cpp
class Solution 
{
private:
    vector<bool> check;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> cur;
        check.resize(nums.size());
        backTrack(ret, nums, cur, 0);
        return ret;
    }

    void backTrack(vector<vector<int>>& ret, vector<int>& nums, vector<int>& cur, int pos)
    {
        if(pos == nums.size())
        {
            ret.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(check[i] || (i > 0 && !check[i - 1] && nums[i] == nums[i - 1]))
                continue;
            else
            {
                cur.push_back(nums[i]);
                check[i] = true;
                backTrack(ret, nums, cur, pos + 1);
                check[i] = false;
                cur.pop_back();
            }
        }
    }
};
```
