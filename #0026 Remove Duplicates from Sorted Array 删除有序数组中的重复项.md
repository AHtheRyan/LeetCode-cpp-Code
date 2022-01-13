### Remove Duplicates from Sorted Array
### 删除有序数组中的重复项

> 给你一个有序数组 `nums`，请你**原地**删除重复出现的元素，使每个元素 **只出现一次**，返回删除后数组的新长度。  
> 不要使用额外的数组空间，你必须在**原地**修改输入数组 并在使用 O(1) 额外空间的条件下完成。  

> Given an integer array `nums` sorted in **non-decreasing** order, remove the duplicates **in-place** such that each unique element appears only **once**. The **relative order** of the elements should be kept the **same**.  
> Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the **first part** of the array `nums`. More formally, if there are `k` elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.  
> Return *`k` after placing the final result in the first `k` slots of `nums`*.  
> Do **not** allocate extra space for another array. You must do this by **modifying the input array** in-place with O(1) extra memory.  

----------

#### I 双指针

从头开始遍历，设立两个指针，一个指向当前要更换的位置，另一个指向下一个新元素，  
每次交换后更新前面的指针，在遇到新元素之前不断更新后面的指针，  
将后者指向的内容赋值给前面的指针即可  

```cpp
int removeDuplicates(vector<int>& nums) 
{
    int size = nums.size();
    if(size < 2)
        return size;
    int left = 0;
    int right = 1;
    while(right < size)
    {
        if(nums[left] == nums[right])
            ++right;
        else
            nums[++left] = nums[right++];
    }
    return left + 1;
}
```
