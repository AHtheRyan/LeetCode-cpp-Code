### 组合总和 II
### Combination Sum II

> 给定一个候选人编号的集合 `candidates` 和一个目标数 `target`，找出 `candidates` 中所有可以使数字和为 `target` 的组合。  
> `candidates` 中的每个数字在每个组合中只能使用**一次**。  
> **注意**：解集不能包含重复的组合。  

> Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.  
> Each number in `candidates` may only be used **once** in the combination.  
> **Note**: The solution set must not contain duplicate combinations.  

----------

#### I 回溯

显而易见的回溯题，  
为了满足**解集中不包含重复元素**的条件，可以利用一个哈希表 `freq` 记录各个数字出现的次数而不是放在数组中遍历处理

```cpp
class Solution 
{
private:
    unordered_map<int, int> freq;
    vector<vector<int>> ret;
    vector<int> cur;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        for(auto candidate : candidates)
            ++freq[candidate];
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ret;
    }

    void backtrack(vector<int>& candidates, int target, int pos)
    {
        if(target == 0)
        {
            ret.push_back(cur);
            return;
        }
        if(pos >= candidates.size())
            return;
        for(int i = 1; i <= freq[candidates[pos]]; ++i)
        {
            int newTarget = target - candidates[pos] * i;
            vector<int> tmp = cur;
            for(int j = 1; j <= i; ++j)
                cur.push_back(candidates[pos]);
            while(pos < candidates.size() - 1 && candidates[pos] == candidates[pos + 1])
                ++pos;
            if(newTarget >= 0)
                backtrack(candidates, newTarget, pos + 1);
            cur = tmp;
        }
        while(pos < candidates.size() - 1 && candidates[pos] == candidates[pos + 1])
            ++pos;
        backtrack(candidates, target, pos + 1);
    }
};
```
