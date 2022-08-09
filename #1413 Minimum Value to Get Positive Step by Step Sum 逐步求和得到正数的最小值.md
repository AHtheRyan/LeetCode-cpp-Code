### 逐步求和得到正数的最小值
### Minimum Value to Get Positive Step by Step Sum

> 给你一个整数数组 `nums`。你可以选定任意的**正数** `startValue` 作为初始值。  
> 你需要从左到右遍历 `nums` 数组，并将 startValue 依次累加上 `nums` 数组中的值。  
> 请你在确保累加和始终大于等于 1 的前提下，选出一个最小的**正数**作为 `startValue`。  

> Given an array of integers `nums`, you start with an initial **positive** value *startValue*.  
> In each iteration, you calculate the step by step sum of *startValue* plus elements in `nums` (from left to right).  
> Return the minimum **positive** value of *startValue* such that the step by step sum is never less than 1.  

----------

#### I 前缀和

在进行累加运算的时候，事实上会把数组中的每个数字都累加一边，因此累加过程中每个值就等于数组元素的累加值与 `startValue` 的和  
我们可以利用前缀和将数组的和求出，之后确定使得求和过程中最小的数字大于等于 1 的值即可  
注意，由于需要最小正数，所以 `startValue` 的值不会小于 `1`  

```cpp
int minStartValue(vector<int>& nums) 
{
    for(int i = 1; i < nums.size(); ++i)
        nums[i] += nums[i - 1];
    int val = INT_MAX;
    for(int i = 0; i < nums.size(); ++i)
        val = min(val, nums[i]);
    return max(1, 1 - val);
}
```
