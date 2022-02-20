### 下一个排列
### Next Permutation

> 整数数组的一个**排列**就是将其所有成员以序列或线性顺序排列。  
> - 例如，`arr = [1,2,3]`，以下这些都可以视作 `arr` 的排列：`[1,2,3]`、`[1,3,2]`、`[3,1,2]`、`[2,3,1]`。  
> 
> 整数数组的**下一个排列**是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的**下一个排列**就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。  
> - 例如，`arr = [1,2,3]` 的下一个排列是 `[1,3,2]`。  
> - 类似地，`arr = [2,3,1]` 的下一个排列是 `[3,1,2]`。  
> - 而 `arr = [3,2,1]` 的下一个排列是 `[1,2,3]`，因为 `[3,2,1]` 不存在一个字典序更大的排列。  
> 
> 给你一个整数数组 `nums`，找出 `nums` 的下一个排列。  
> 必须 **`原地`** 修改，只允许使用额外常数空间。  

> A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.  
> - For example, for `arr = [1,2,3]`, the following are considered permutations of `arr`: `[1,2,3]`, `[1,3,2]`, `[3,1,2]`, `[2,3,1]`.  
> 
> The **next permutation** of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the **next permutation** of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order). 
> - For example, the next permutation of `arr = [1,2,3]` is `[1,3,2]`.  
> - Similarly, the next permutation of `arr = [2,3,1]` is `[3,1,2]`.  
> - While the next permutation of `arr = [3,2,1]` is `[1,2,3]` because `[3,2,1]` does not have a lexicographical larger rearrangement.  
> 
> Given an array of integers `nums`, *find the next permutation of `nums`*.  
> The replacement must be **`in place`** and use only constant extra memory.  

----------

#### I 排列算法

找到下一个排列的数学方法如下：  
1. 找出最靠右的连续递增数对，则小的那个成为左侧元素  
2. 找出左侧元素右边的元素，满足：  
   - 该元素大于左侧元素  
   - 该元素尽可能靠右  
   
   成为右侧元素
3. 交换两个元素  
4. 此时左侧元素所在位置右边为递减，将其反转

如此便可得到下一个排列  

```cpp
void nextPermutation(vector<int>& nums) 
{
    int n = nums.size();
    int minIndex = n - 2;
    while(minIndex >= 0 && nums[minIndex] >= nums[minIndex + 1])
        --minIndex;
    int bigIndex = minIndex + 1;
    if(minIndex >= 0)
    {
        for(int j = bigIndex; j < n - 1; ++j)
            if(nums[j] >= nums[j + 1] && nums[j + 1] > nums[minIndex])
                bigIndex = j + 1;
        swap(nums[minIndex], nums[bigIndex]);
    }
    reverse(nums.begin() + minIndex + 1, nums.end()); 
}
```
