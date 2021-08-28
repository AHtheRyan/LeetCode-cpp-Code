### 一维数组的动态和
### Running Sum of 1d Array

> 给你一个数组 `nums` 。数组「动态和」的计算公式为：`runningSum[i] = sum(nums[0]…nums[i])`  
> 请返回 `nums` 的动态和。  

> Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]…nums[i])`.  
> Return the running sum of `nums`.

----------

#### I 前缀和

根据题意，每个下标位置的值都是该位置和之前位置的累加和，  
很容易得出迭代的公式  
**注意**：根据此方法得到的数列同时也是一维数组的前缀和

```cpp
vector<int> runningSum(vector<int>& nums) 
{
    for(int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];
    return nums;
}
```
