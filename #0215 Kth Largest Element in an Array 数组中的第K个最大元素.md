### 数组中的第K个最大元素
### Kth Largest Element in an Array

> 给定整数数组 `nums` 和整数 `k`，请返回数组中第 `k` 个最大的元素。  
> 请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。  

> Given an integer array `nums` and an integer `k`, return *the `kth` largest element in the array*.  
> Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.  

----------

#### I 快速选择

由于只需要求数组中第K大的元素，可利用快速选择法，求得下标为 `nums.size() - k` 的元素即可  
快速选择法的思路与快速排序相同，不同处在于只需要找到某特定位置的元素

```cpp
int findKthLargest(vector<int>& nums, int k) 
{
    int l = 0;
    int r = nums.size() - 1;
    int tar = nums.size() - k;
    while(l < r)
    {
        int mid = quick_selection(nums, l, r);
        if(mid == tar)
            return nums[mid];
        else if(mid > tar)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return nums[l];
}

int quick_selection(vector<int>& nums, int l, int r)
{
    int left = l + 1;
    int right = r;
    while(true)
    {
        while(left < r && nums[left] <= nums[l])
            ++left;
        while(right > l && nums[right] >= nums[l])
            --right;
        if(left >= right)
            break;
        swap(nums[left], nums[right]);
    }
    swap(nums[l], nums[right]);
    return right;
}
```
