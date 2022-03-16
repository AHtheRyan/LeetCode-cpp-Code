### 0~n-1中缺失的数字

> 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。  

----------

#### I 二分查找

简单二分

```cpp
int missingNumber(vector<int>& nums) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
```
