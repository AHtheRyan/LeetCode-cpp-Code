### 删除有序数组中的重复项
### Remove Duplicates from Sorted Array

> 给你一个有序数组 `nums`，请你**原地**删除重复出现的元素，使每个元素**最多出现两次**，返回删除后数组的新长度。  
> 不要使用额外的数组空间，你必须在**原地**修改输入数组 并在使用O(1)额外空间的条件下完成。  

> Given an integer array `nums` sorted in **non-decreasing order**, remove some duplicates **in-place** such that each unique element appears **at most twice**. The **relative order** of the elements should be kept the **same**.  
> Return `k` *after placing the final result in the first `k` slots of `nums`*.  
> Do **not** allocate extra space for another array. You must do this by **modifying the input array** in-place with O(1) extra memory.  

----------

#### I 双指针

利用双指针解决问题，使用一个指针 `left` 始终指向可能需要修改的元素，使用另一个指针 `right` 进行移动并与可能需要修改的元素进行比较：  
- 如果需要修改的元素不是重复出现超过两次的元素，则将 `left` 和 `right` 元素交换并将两个指针右移  
- 如果需要修改的元素是重复出现超过两次的元素，则将 `right` 指针右移  

利用 `right` 指针遍历整个数组，实现“删除”功能  

```cpp
int removeDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    if(n <= 2)
        return n;
    int left = 2;
    int right = 2;
    while(right < n)
    {
        if(nums[left - 2] != nums[right])
            nums[left++] = nums[right];
        ++right;
    }
    return left;
}
```
