### 在排序数组中查找数字

> 统计一个数字在排序数组中出现的次数。  

----------

#### I 二分查找

见[在排序数组中查找元素的第一个和最后一个位置](./%230034%20Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array%20在排序数组中查找元素的第一个和最后一个位置.md)

```cpp
int search(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    int start = -1;
    int end = -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(mid == 0 || nums[mid - 1] < target)
        {
            start = mid;
            break;
        }
        else
            right = mid - 1;
    }
    if(start == -1)
        return 0;
    left = start;
    right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > target)
            right = mid - 1;
        else if(mid == nums.size() - 1 ||nums[mid + 1] > target)
        {
            end = mid;
            break;
        }
        else
            left = mid + 1;
    }
    return end - start + 1;
}
```
