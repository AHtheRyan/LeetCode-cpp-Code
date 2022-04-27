### 按奇偶排序树组
### Sort Array by Parity

> 给你一个整数数组 `nums`，将 `nums` 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。  

> Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.  

----------

#### I 双指针

简单双指针

```cpp
vector<int> sortArrayByParity(vector<int>& nums) 
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        while(left < right && nums[left] % 2 == 0)
            ++left;
        while(left < right && nums[right] % 2 == 1)
            --right;
        swap(nums[left++], nums[right--]);
    }
    return nums;
}
```
