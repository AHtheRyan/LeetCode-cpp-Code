### 丢失的数字
### Missing Number

> 给定一个包含 `[0, n]` 中 `n` 个数的数组 `nums`，找出 `[0, n]` 这个范围内没有出现在数组中的那个数。  

> Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array*.  

----------

#### I 位运算

利用 `x ^ x = 0` 的性质，可以遍历数组找出丢失的数字

```cpp
int missingNumber(vector<int>& nums) 
{
    int n = nums.size();
    int ret = 0;
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        ret ^= nums[i];
        ret ^= count++;
    }
    return ret ^ count;
}
```

#### II 数学

利用等差数列的和与实际数组和的差值，可以求出丢失的数字

```cpp
int missingNumber(vector<int>& nums) 
{
    int n = nums.size();
    int sum = (1 + n) * n / 2;
    int all = accumulate(nums.begin(), nums.end(), 0);
    return sum - all;
}
```
