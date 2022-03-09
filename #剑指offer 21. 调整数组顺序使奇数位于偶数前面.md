### 调整数组顺序使奇数位于偶数前面

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。  

---------

#### I 双指针

从两端遍历，分别定位在偶数和奇数，每次交换即可  

```cpp
vector<int> exchange(vector<int>& nums) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        while(left < right && nums[left] % 2)
            ++left;
        while(left < right && nums[right] % 2 == 0)
            --right;
        swap(nums[left], nums[right]);
    }
    return nums;
}
```
