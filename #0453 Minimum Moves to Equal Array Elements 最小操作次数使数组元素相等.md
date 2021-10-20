### 最小操作次数使数组元素相等
### Minimum Moves to Equal Array Elements

> 给你一个长度为 `n` 的整数数组，每次操作将会使 `n - 1` 个元素增加 `1` 。返回让数组所有元素相等的最小操作次数。  

> Given an integer array `nums` of size `n`, return *the minimum number of moves required to make all array elements equal*.  
> In one move, you can increment `n - 1` elements of the array by `1`.  

----------

#### I 数学

可以将题目转化为每次使得 **1** 个元素减少 **1**，这样就只需要求出最小元素以及每个元素和最小元素的差值即可

```cpp
int minMoves(vector<int>& nums) 
{
    int size = nums.size();
    int min = INT_MAX;
    int ret = 0;
    for(int i = 0; i < size; ++i)
        min = min < nums[i] ? min : nums[i];
    for(int i = 0; i < size; ++i)
        ret += nums[i] - min;
    return ret;
}
```
