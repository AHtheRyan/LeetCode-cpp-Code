### 二倍数对数组
### Array of Doubled Pairs

> 给定一个长度为偶数的整数数组 `arr`，只有对 `arr` 进行重组后可以满足 “对于每个 `0 <= i < len(arr) / 2`，都有 `arr[2 * i + 1] = 2 * arr[2 * i]`” 时，返回 `true`；否则，返回 `false`。  

> Given an integer array of even length `arr`, return `true` *if it is possible to reorder arr such that `arr[2 * i + 1] = 2 * arr[2 * i]` for every `0 <= i < len(arr) / 2`, or `false` otherwise*.  

----------

#### I 哈希表 + 排序

利用哈希表记录下每个数字的个数，再对原数组进行集合化处理，每个数字只留一个，最后对每个数字进行分析，判断其二倍数是否存在，如果存在则将二倍数减去改数字的树木（视为已经匹配），否则返回 `false`  

```cpp
bool canReorderDoubled(vector<int>& arr)
{
    unordered_map<int, int> mp;
    for(auto& num : arr)
        ++mp[num];
    vector<int> rec;
    for(auto& p : mp)
        rec.emplace_back(p.first);
    sort(rec.begin(), rec.end(), [](int a, int b){return abs(a) < abs(b);});
    for(int i = 0; i < rec.size(); ++i)
    {
        if(mp[rec[i]] > mp[rec[i] * 2])
            return false;
        mp[rec[i] * 2] -= mp[rec[i]];
    }
    return true;
}
```
