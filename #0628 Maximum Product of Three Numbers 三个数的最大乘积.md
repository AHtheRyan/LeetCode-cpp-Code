### 三个数的最大乘积
### Maximum Product of Three Numbers

> 给你一个整型数组 `nums`，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

> Given an integer array `nums`, *find three numbers whose product is maximum and return the maximum product*.  

----------

#### I 排序

将数组排序，结果必然为最大的三个正数或者最小的两个负数和最大的一个正数的乘积之一，比较并返回即可  

```cpp
int maximumProduct(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n -1] * nums[0] * nums[1]);
}
```
