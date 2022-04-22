### 旋转函数
### Rotate Function

> 给定一个长度为 `n` 的整数数组 `nums`。  
> 假设 `arrk` 是数组 `nums` 顺时针旋转 `k` 个位置后的数组，我们定义 `nums` 的**旋转函数** `F` 为：  
> -  `F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]`  
> 
> 返回 *`F(0), F(1), ..., F(n-1)`中的最大值*。  

> You are given an integer array `nums` of length `n`.  
> Assume `arrk` to be an array obtained by rotating `nums` by `k` positions clock-wise. We define the **rotation function** `F` on `nums` as follow:  
> - `F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1]`.  
> 
> Return *`the maximum value of F(0), F(1), ..., F(n-1)`*.  

----------

#### I 规律推导

给出了公式可以按照递推关系找到规律  

```cpp
int maxRotateFunction(vector<int>& nums) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int cur = 0;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
        cur += (i * nums[i]);
    int ret = cur;
    for(int i = 0; i < n; ++i)
    {
        cur -= sum;
        cur += nums[i] * n;
        ret = max(ret, cur);
    }
    return ret;
}
```
