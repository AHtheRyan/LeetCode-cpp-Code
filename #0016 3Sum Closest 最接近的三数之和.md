### 最接近的三数之和
### 3Sum Closest

> 给你一个长度为 `n` 的整数数组 `nums` 和 一个目标值 `target`。请你从 `nums` 中选出三个整数，使它们的和与 `target` 最接近。  
> 返回这三个数的和。  
> 假定每组输入只存在恰好一个解。  

> Given an integer array `nums` of length `n` and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.  
> Return *the sum of the three integers*.  
> You may assume that each input would have exactly one solution.  

----------

#### I 排序 + 双指针

基本思路与 [3Sum 三数之和](./%230015%203%20Sum%20三数之和.md) 类似  
先排序，利用三数之和最接近 `target` 的要求，缩小 `mid` 和 `right` 的范围  
求得最接近的值即可

```cpp
int threeSumClosest(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int minDif = INT_MAX;
    int left = 0;
    int ret = 0;
    for(; left < size - 2; ++left)
    {
        if(left > 0 && nums[left - 1] == nums[left])
            continue;
        int right = size - 1;
        int mid = left + 1;
        while(mid < right)
        {
            if(mid > left + 1 && nums[mid - 1] == nums[mid])
            {
                ++mid;
                continue;
            }
            else if(right < size - 1 && nums[right] == nums[right + 1])
            {
                --right;
                continue;
            }
            int sum = nums[left] + nums[mid] + nums[right];
            if(sum == target)
                return sum;
            else if(target > sum)
                ++mid;
            else
                --right;
            int dif = abs(sum - target);
            if(dif < minDif)
            {
                ret = sum;
                minDif = dif;
            }
        }
    }
    return ret;
}
```
