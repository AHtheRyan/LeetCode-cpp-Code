### K次取反后最大化的数组和
### Maximize Sum Of Array After K Negations

> 给你一个整数数组 `nums` 和一个整数 `k`，按以下方法修改该数组：  
> - 选择某个下标 `i` 并将 `nums[i]` 替换为 `-nums[i]`。  
> 
> 重复这个过程恰好 `k` 次。可以多次选择同一个下标 `i`。  
> 以这种方式修改数组后，返回数组 **可能的最大和**。  

> Given an integer array `nums` and an integer `k`, modify the array in the following way:  
> - choose an index `i` and replace `nums[i]` with `-nums[i]`.  
> 
> You should apply this process exactly `k` times. You may choose the same index `i` multiple times.  
> Return *the largest possible sum of the array after modifying it in this way*.  

----------

#### I 排序 + 贪心

显然，我们不断改变最小的负数的符号即可认为使得数组和在不断变大，主要问题在于是否数组能一直变大，考虑条件如下：
- 负数数量大于等于 `k`，则必然可以满足，只要改变最小的 `k` 个数字即可
- 负数数量小于 `k`，则需要考虑是否有 `0`：
  - 如果有 `0`，可在负数都变为正数后对 `0` 做任意次改变，值恒为最大
  - 如果无 `0`，且变换 `m` 次后有 `(k - m) % 2 == 0`，即还剩偶数次变换，则无影响，仍然为最小
  - 如果无 `0`，且变换 `m` 次后有 `(k - m) % 2 == 1`，即还剩奇数次变换，则将数组中的最小值减去两次即可（第一次是加和，第二次是本身）

```cpp
int largestSumAfterKNegations(vector<int>& nums, int k) 
{
    sort(nums.begin(), nums.end());
    int cntN = 0;
    bool zero = false;
    int ret = 0;
    for(auto& num : nums)
    {
        if(num < 0)    ++cntN;
        if(num == 0)    zero = true;
    }
    if(k >= cntN)
    {
        for(auto& num : nums)
        {
            num = abs(num);
            ret  += num;
        }
        if(!zero && (k - cntN) % 2)
        {
            sort(nums.begin(), nums.end());
            ret -= (nums[0] * 2);
        }
    }
    else
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i < k)
                ret -= nums[i];
            else
                ret += nums[i];
        }
    }
    return ret;
}
```
