### 连续子数组的最大和

> 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。  
> 要求时间复杂度为O(n)。  

----------

#### I 动态规划

见[最大子数组和](./%230053%20Maximum%20Subarray%20最大子数组和.md)  

```cpp
int maxSubArray(vector<int>& nums) 
{
    int cur = nums[0];
    int ret = cur;
    for(int i = 1; i < nums.size(); ++i)
    {
        if(cur + nums[i] > nums[i])
            cur += nums[i];
        else
            cur = nums[i];
        ret = max(cur, ret);
    }
    return ret;
}
```

#### II 分治法

见[最大子数组和](%230053%20Maximum%20Subarray%20最大子数组和.md)  

```cpp
class Solution 
{
public:
    struct Sum
    {
        int sumleft;
        int sumright;
        int sumall;
        int sumcenter;
    };

    Sum div(vector<int>& nums, int start, int end)
    {
        if(start == end)
            return Sum{nums[start], nums[start], nums[start], nums[start]};
        int mid = start + (end - start) / 2;
        Sum cmp1 = div(nums, start, mid);
        Sum cmp2 = div(nums, mid +1, end);
        return calculate(cmp1, cmp2);
    }

    Sum calculate(Sum& cmp1, Sum& cmp2)
    {
        Sum ret;
        ret.sumleft = max(cmp1.sumleft, cmp1.sumall + cmp2.sumleft);
        ret.sumright = max(cmp2.sumright, cmp2.sumall + cmp1.sumright);
        ret.sumall = cmp1.sumall + cmp2.sumall;
        ret.sumcenter = max(cmp1.sumright + cmp2.sumleft, max(cmp1.sumcenter, cmp2.sumcenter));
        return ret;
    }

    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        Sum ret = div(nums, 0, n - 1);
        return ret.sumcenter;
    }
};
```
