### 求众数 II
### Majority Element II

> 给定一个大小为 n 的整数数组，找出其中所有出现超过 `⌊ n/3 ⌋` 次的元素。

> Given an integer array of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.  

----------

#### I 排序

将数组排序，确定众数的要求后，对每个数字计数即可

```cpp
vector<int> majorityElement(vector<int>& nums) 
{
    int size = nums.size();
    int times = size / 3;
    sort(nums.begin(), nums.end());
    vector<int> ret;
    int cnt = 1;
    int cur = nums[0];
    for(int i = 1; i < size; ++i)
    {
        if(cur == nums[i])
            ++cnt;
        else
        {
            if(cnt > times)
                ret.push_back(cur);
            cur = nums[i];
            cnt = 1;
        }
    }
    if(cnt > times)
        ret.push_back(cur);
    return ret;
}
```

#### II 哈希表

直接利用哈希表确定每个数字的出现次数，返回出现次数满足要求的数字集合

```cpp
vector<int> majorityElement(vector<int>& nums) 
{
    int size = nums.size();
    int times = size / 3;
    vector<int> ret;
    unordered_map<int, int> mp;
    for(auto num : nums)
        ++mp[num];
    for(auto it: mp)
        if(it.second > times)
            ret.push_back(it.first);
    return ret;
}
```
