### 组和总和
### Combination Sum

> 给你一个**无重复元素**的整数数组 `candidates` 和一个目标整数 `target`，找出 `candidates` 中可以使数字和为目标数 `target` 的*所有***不同组合**，并以列表形式返回。你可以按**任意顺序**返回这些组合。  
> `candidates` 中的 同一个 数字可以**无限制重复被选取**。如果至少一个数字的被选数量不同，则两种组合是不同的。   
> 对于给定的输入，保证和为 `target` 的不同组合数少于 `150` 个。  

> Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of `candidates` where the chosen numbers sum to `target`*. You may return the combinations in **any order**.  
> The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.  
> It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.  

----------

#### I 回溯算法v1.0

显而易见的回溯算法题  
这里采用一个循环来解决问题，每次以当前回溯过程遍历到的数字为起点，将其加入当前的数组中查看是否可以得到和为 `target`  
需要注意的问题是，采用循环的方式必须默认 `candidates` 数组是默认单调递增的，因此需要加入一个 `sort()` 函数  

```cpp
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, cur, 0, target, ret);
        return ret;
    }

    void backTrack(vector<int>& candidates, vector<int>& cur, int pos, int target, vector<vector<int>>& ret)
    {
        if(target == 0)
        {
            ret.push_back(cur);
            return;
        }
        if(pos == candidates.size())
            return;
        for(int i = pos; i < candidates.size(); ++i)
        {
            vector<int> tmp = cur;
            int newTarget = target - candidates[i];
            if(newTarget < 0)
                return;
            cur.push_back(candidates[i]);
            backTrack(candidates, cur, i, newTarget, ret);
            cur = tmp;
        }
    }
};
```

### II 回溯算法v1.1

可以采用一个 `if()` 语句避免需要先进行排序的问题  
判断当前未知的数字是否能进一步被利用，如果能，就再以当前位置为基准进行一次判断，如果不能，则直接进入下一个数字的判断即可  

```cpp
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ret;
        vector<int> cur;
        backTrack(candidates, cur, 0, target, ret);
        return ret;
    }

    void backTrack(vector<int>& candidates, vector<int>& cur, int pos, int target, vector<vector<int>>& ret)
    {
        if(target == 0)
        {
            ret.push_back(cur);
            return;
        }
        if(pos == candidates.size())
            return;
        if(target - candidates[pos] >= 0)
        {
            vector<int> tmp = cur;
            cur.push_back(candidates[pos]);
            backTrack(candidates, cur, pos, target - candidates[pos], ret);
            cur = tmp;
        }
        backTrack(candidates, cur, pos + 1, target, ret);
    }
};
```
