### 移动零
### Move Zeroes

> 给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。  
> **请注意**，必须在不复制数组的情况下原地对数组进行操作。  

> Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.  
> **Note** that you must do this in-place without making a copy of the array.  

----------

#### I 双指针

利用两个指针，一个指向 `0`，另一个指向非 `0` 元素，交换后两个指针指向后续符合条件的数字即可  

```cpp
void moveZeroes(vector<int>& nums) 
{
    int left = 0;
    int right = 0;
    int n = nums.size();
    while(left < n && right < n)
    {
        while(right < n && nums[right] == 0)
            ++right;
        while(left < right && nums[left] != 0)
            ++left;
        if(right < n)
            swap(nums[left++], nums[right++]);
    }
}
```
