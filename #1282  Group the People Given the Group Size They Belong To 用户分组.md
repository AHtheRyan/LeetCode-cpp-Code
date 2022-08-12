### 用户分组
### Group the People Given the Group Size They Belong To

> 有 `n` 个人被分成数量未知的组。每个人都被标记为一个从 `0` 到 `n - 1` 的**唯一ID**。  
> 给定一个整数数组 `groupSizes`，其中 `groupSizes[i]` 是第 `i` 个人所在的组的大小。例如，如果 `groupSizes[1] = 3`，则第 `1` 个人必须位于大小为 `3` 的组中。  
> 返回一个组列表，使每个人 `i` 都在一个大小为 *`groupSizes[i]`* 的组中。  
> 每个人应该**恰好只**出现在**一个组**中，并且每个人必须在一个组中。如果有多个答案，返回其中**任何**一个。可以**保证**给定输入**至少有一个**有效的解。  

> There are `n` people that are split into some unknown number of groups. Each person is labeled with a **unique ID** from `0` to `n - 1`.  
> You are given an integer array `groupSizes`, where `groupSizes[i]` is the size of the group that person `i` is in. For example, if `groupSizes[1] = 3`, then person `1` must be in a group of size `3`.  
> Return *a list of groups such that each person `i` is in a group of size `groupSizes[i]`*.  
> Each person should appear in **exactly one group**, and every person must be in a group. If there are multiple answers, **return any of them**. It is **guaranteed** that there will be **at least one** valid solution for the given input.  

----------

#### I 哈希表

利用哈希表记录每个人所在组的确切人数，之后对不同人数的组进行分类即可  

```cpp
vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
{
    unordered_map<int, vector<int>> mp;
    for(int i = 0;  i < groupSizes.size(); ++i)
        mp[groupSizes[i]].push_back(i);
    vector<vector<int>> ret;
    for(auto& group : mp)
    {
        int group_size = group.first;
        int sum = group.second.size();
        if(sum == group_size)
            ret.emplace_back(group.second);
        else
        {
            int n = sum / group_size;
            for(int i = 0; i < n; ++i)
            {
                vector<int> cur;
                for(int j = 0; j < group_size; ++j)
                    cur.push_back(group.second[j + group_size * i]);
                ret.emplace_back(cur);
            }
        }
    }
    return ret;
}
```
