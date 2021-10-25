### 颜色分类
### Sort Colors

> 给定一个包含红色、白色和蓝色，一共 `n` 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。  
> 此题中，我们使用整数 `0`、 `1` 和 `2` 分别表示红色、白色和蓝色。  

> Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.  
> We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.  
> You must solve this problem without using the library's sort function.

----------

### I 双指针

换皮排序题，由于只有0, 1, 2 三个数字，我们可以从左到右遍历数组，同时对左右两个端点设置指针  
1. 如果遍历位置的值为 2，将其与右端点换位，将右端点指针减一  
2. 如果遍历位置的值为 0，将其与左端点换位，将左端点和便利位置的指针都加一  
3. 如果遍历位置的值为 1，则跳过该位置  

```cpp
void sortColors(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;
    int move = 0;
    while(move <= right)
    {
        if(nums[move] == 0)
            swap(nums[move++], nums[left++]);
        else if(nums[move] == 2)
            swap(nums[move], nums[right--]);
        else
            ++move;
    }
}
```

#### II 计数

由于只有三种颜色，可以记录下三种颜色的数量，之后再对原数组依次按三个数字的数目赋值即可

```cpp
void sortColors(vector<int>& nums) 
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(auto num : nums)
    {
        if(num == 0)
            ++count0;
        else if(num == 1)
            ++count1;
        else
            ++count2;
    }
    int index = 0;
    while(count0--)
        nums[index++] = 0;
    while(count1--)
        nums[index++] = 1;
    while(count2--)
        nums[index++] = 2;
}
```
