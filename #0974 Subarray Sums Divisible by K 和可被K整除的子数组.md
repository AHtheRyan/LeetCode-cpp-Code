### 和可被K整除的子数组
### Subarray Sums Divisible by K

> 给定一个整数数组 `nums` 和一个整数 `k`，返回其中元素之和可被 `k` 整除的（连续、非空）**子数组**的数目。  
> **子数组**是数组的**连续**部分。  

> Given an integer array `nums` and an integer `k`, return *the number of non-empty **subarrays** that have a sum divisible by `k`*.  
> A **subarray** is a **contiguous** part of an array.  

----------

#### I 前缀和 + 同余定理

根据同余定理，整除 `k` 取余后相同的数字只差可以被 `k` 整除，因此可以利用此定理与前缀和快速求解  

```cpp
int subarraysDivByK(vector<int>& nums, int k) 
{
    int sum = 0;
    int ret = 0;
    unordered_map<int, int> cal{{0, 1}};
    for(auto num : nums)
    {
        sum += num;
        int mod = (sum % k + k) % k;
        ++cal[mod];
    }
    for(auto& p : cal)
        ret += p.second * (p.second - 1) / 2;
    return ret;
}
```
