### 至少是其他数字两倍的最大数
### Largest Number At Least Twice of Others

> 给你一个整数数组 `nums`，其中总是存在**唯一的**一个最大整数。  
> 请你找出数组中的最大元素并检查它是否**至少是数组中每个其他数字的两倍**。如果是，则返回**最大元素的下标**，否则返回 `-1`。  

> You are given an integer array `nums` where the largest integer is **unique**.  
> Determine whether the largest element in the array is **at least twice** as much as every other number in the array. If it is, return *the **index** of the largest element, or return `-1` otherwise.*  

----------

#### I 一次遍历

遍历数组，记录最大和第二大的元素，按照要求进行比较即可  

```cpp
int dominantIndex(vector<int>& nums) 
{
    int first = INT_MIN;
    int second = INT_MIN;
    int index = -1;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > first)
        {
            index = i;
            second = first;
            first = nums[i];
        }
        else if(nums[i] > second)
            second = nums[i];
    }
    return first / 2 >= second ? index : -1;
}
```
