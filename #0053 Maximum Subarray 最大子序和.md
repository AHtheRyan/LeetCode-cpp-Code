### 最大子数组和
### Maximum Subarray

> 给你一个整数数组 `nums`，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。  
> **子数组**是数组中的一个连续部分。  

> Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*.  
> A **subarray** is a **contiguous** part of an array.  

----------

#### I 动态规划

根据题目要求，按顺序遍历数组，从下标 `0` 开始到下标最大的位置，每个位置都有对应的最大子序列和，  
例如，在数列 `[-2, 1, -3, 4, -1, 2, 1, -5, 4]` 中:  
- 下标 `“0”` 对应的最大子序和就是 `“-2”`，
- 下标 `“1”` 对应的则有两种可能：
   - 只取本身，即 `“1”`
   - 前面的最大子序和加上当前数字，即 `“-1”`，显然，取二者最大值即可，后续同理  

即对每个下标而言，截止到该位置的最大子序和的值是单独取该位置的值或者前面的最大子序和加上该位置的值中较大的那个，  
因此，可以遍历一遍数组，得到每个位置的最大子序和，取其中的最大值。  

```cpp
//v1.0
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    dp[0] = nums[0];
    for (int i = 1; i < size; ++i)
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
    return *max_element(dp.begin(), dp.end());
}

//v1.1
//remove vector dp, use a single variable to store the result, which saves the memory
//取消了dp数组的构建，使用一个单独的变量存储，节约了空间的使用
int maxSubArray(vector<int>& nums)
{
    int size = nums.size();
    int max = nums[0];
    int cur = max;
    for (int i = 1; i < size; ++i)
    {
        cur = nums[i] + cur > nums[i] ? nums[i] + cur : nums[i];
        max = cur > max ? cur : max;
    }
    return max;
}
```

#### II 分治

分治同样可解  
分析原数组，不难发现，对于任意数组，最大子序和只有四种可能：  
1. 整个数组 `allsum`  
2. 中间一段子数组 `midsum`  
3. 从左开始的一段子数组 `leftsum`  
4. 从中间开始直到右边末尾的子数组 `rightsum`  

如果把一个数组一分为二，则同样，两个子数组也是只有这四种可能，  
将两个数组合并时可分析如下：  
1. 新的 `midsum` 为左右两个 `midsum` 和左`rightsum`与右`leftsum` 的和中的较大者
2. 新的 `leftsum` 为左`leftsum`和左`allsum`与右`leftsum`的和中的较大者
3. 新的 `rightsum`为右`rightsum`和右`allsum`与左`rightsum`的和中的较大者
4. 新的 `allsum`为左右`allsum`之和  

采用分治的思路更新即可  

```cpp
class Solution 
{
public:
    struct difSum
    {
        int leftSum;
        int rightSum;
        int midSum;
        int allSum;
    };

    difSum pushUp(difSum left, difSum right)
    {
        int lSum = max(left.leftSum, left.allSum + right.leftSum);
        int rSum = max(right.rightSum, right.allSum + left.rightSum);
        int midSum = max(left.rightSum + right.leftSum, max(left.midSum, right.midSum));
        int allSum = left.allSum + right.allSum;
        return difSum {lSum, rSum, midSum, allSum};
    }

    difSum div(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return difSum {nums[left], nums[left], nums[left], nums[left]};
        int mid = left + (right - left) / 2;
        difSum cand1 = div(nums, left, mid);
        difSum cand2 = div(nums, mid + 1, right);
        return pushUp(cand1, cand2);
    }

    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        return div(nums, 0, n - 1).midSum;
    }
};
```
