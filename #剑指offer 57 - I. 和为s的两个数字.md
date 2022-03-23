### 和为s的两个数字

> 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。  

----------

#### I 双指针

对于一个递增数组而言，左右端数字之和可以反映一个趋势：  
- 和大于 `target`，说明右边数字可以缩小，右边指针左移  
- 和小于 `target`，说明左边数字可以增大，左边指针右移  

在此过程中匹配 `target` 即可  

```cpp
vector<int> twoSum(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)
            return {nums[left], nums[right]};
        else if(sum > target)
            --right;
        else
            ++left;
    }
    return {};
}
```
