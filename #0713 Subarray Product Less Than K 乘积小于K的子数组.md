### 乘积小于K的子数组
### Subarray Product Less Than K  

> 给你一个整数数组 `nums` 和一个整数 `k`，请你返回子数组内所有元素的乘积严格小于 `k` 的连续子数组的数目。  

> Given an array of integers `nums` and an integer `k`, return *the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than `k`*.  

----------

#### I 滑动窗口

探究连续数字的数组数量可以发现：  
- 有一个元素 `[a]` 时，新增子数组为 `1` 个，即 `[a]`
- 有两个元素 `[a, b]` 时，新增子数组为 `2` 个，即 `[b]` `[a, b]`  
- 有三个元素时 `[a, b, c]`，新增子数组为 `3` 个，即 `[c]` `[b, c]` `[a, b, c]`  

依次类推，即增加第 `k` 个符合的连续数字时，共增加了 `k` 个新的子数组  
可采用滑动窗口进行判断  

```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) 
{
    int n = nums.size();
    int ret = 0;
    int left = 0;
    int right = 0;
    int cur = 1;
    while(right < n)
    {
        cur *= nums[right];
        while(cur >= k && left <= right)
        {
            cur /= nums[left];
            ++left;
        }
        ret += right - left + 1;
        ++right;
    }
    return ret;
}
```
