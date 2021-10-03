### 数组美丽值求和
### Sum of Beauty in the Array

> 给你一个下标从 **0** 开始的整数数组 `nums`。对于每个下标 `i`（`1 <= i <= nums.length - 2`），`nums[i]` 的**美丽值**等于：  
> - `2`，对于所有 `0 <= j < i` 且 `i < k <= nums.length - 1`，满足 `nums[j] < nums[i] < nums[k]`  
> - `1`，如果满足 `nums[i - 1] < nums[i] < nums[i + 1]`，且不满足前面的条件  
> - `0`，如果上述条件全部不满足  
>  
>  返回符合 `1 <= i <= nums.length - 2` 的所有 `nums[i]` 的**美丽值的总和**。  

> You are given a **0-indexed** integer array `nums`. For each index `i` (`1 <= i <= nums.length - 2`) the **beauty** of `nums[i]` equals:  
> - `2`, if `nums[j] < nums[i] < nums[k]`, for **all** `0 <= j < i` and for **all** `i < k <= nums.length - 1`.  
> - `1`, if `nums[i - 1] < nums[i] < nums[i + 1]`, and the previous condition is not satisfied.  
> - `0`, if none of the previous conditions holds.  
>  
>  Return *the **sum of beauty** of all `nums[i]` where `1 <= i <= nums.length - 2`*.

----------

#### I 哈希表

显然，对于每个位置 `i` 满足 `1 <= i <= nums.length - 2` 的数字而言，需要知道的是这个数字相对于**左侧所有数中最大数**、**紧邻左侧数字**、**右侧所有数中最小数**、**紧邻右侧数字**的关系，  
因此，可以分别从左至右、从右至左各遍历一次数组，每次在该数字所在的位置记录下 **从左至右到该位置之前的最大数** 和 **从右至左到该位置之前的最小数**，  
最后遍历符合条件的所有点，按照美丽值的规则分别计算每个点的美丽值并求和即可

```cpp
int sumOfBeauties(vector<int>& nums) 
{
    int size = nums.size();
    vector<vector<int>> beauty(2, vector<int>(size));
    beauty[0][0] = nums[0];
    beauty[1][size - 1] = nums[size - 1];
    int ret = 0;
    for(int i = 1; i < size; ++i)
        beauty[0][i] = nums[i] > beauty[0][i - 1] ? nums[i] : beauty[0][i - 1];
    for(int i = size - 2; i >= 0; --i)
        beauty[1][i] = nums[i] < beauty[1][i + 1] ? nums[i] : beauty[1][i + 1];
    for(int i = 1; i < size - 1; ++i)
    {
        if(nums[i] > beauty[0][i - 1] && nums[i] < beauty[1][i + 1])
            ret += 2;
        else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
            ret += 1;
    }
    return ret;
}
```
