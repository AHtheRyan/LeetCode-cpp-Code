### 前 K 个高频元素
### Top K Frequent Elements

> 给你一个整数数组 `nums` 和一个整数 `k`，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。  

> Given an integer array `nums` and an integer `k`, return *the `k` most frequent elements*. You may return the answer in *any order*.  

----------

#### I 桶排序

先将每个数字出现的次数，以及出现最多的次数用哈希表记录，  
再将每个数字按照 “出现次数-数字” 的对应顺序记录在数列中，  
最后从大到小输出前 k 个数字即可

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    unordered_map<int, int> mp;
    int maxEle = 0;
    for(auto num : nums)
        maxEle = max(maxEle, ++mp[num]);
    vector<vector<int>> barrel(maxEle + 1);
    for(auto it : mp)
        barrel[it.second].push_back(it.first);
    vector<int> ret;
    for(int i = maxEle; i >= 0 && ret.size() < k; --i)
    {
        for(auto ele : barrel[i])
            ret.push_back(ele);
        if(ret.size() == k)
            break;
    }
    return ret;
}
```
