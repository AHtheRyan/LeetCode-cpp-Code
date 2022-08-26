### 数组中两元素的最大乘积
### Maximum Product of Two Elements in an Array

> 给你一个整数数组 `nums`，请你选择数组的两个不同下标 `i` 和 `j`，使 `(nums[i]-1)*(nums[j]-1)` 取得最大值。  
> 请你计算并返回该式的最大值。  

> Given the array of integers `nums`, you will choose two different indices `i` and `j` of that array. *Return the maximum value of `(nums[i]-1)*(nums[j]-1)`*.  

----------

#### I 遍历

简单遍历找到最大的两个数字即可  

```cpp
int maxProduct(vector<int>& nums) 
{
    int n1 = 0;
    int n2 = 0;
    for(auto& num : nums)
    {
        if(num >= n1)
        {
            n2 = n1;
            n1 = num;
        }
        else if(num > n2)
            n2 = num;
    }
    return (n1 - 1) * (n2 - 1);
}
```
