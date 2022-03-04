### 子数组的范围和
### Sum of Subarray Ranges

> 给你一个整数数组 `nums`。`nums` 中，子数组的**范围**是子数组中最大元素和最小元素的差值。  
> 返回 `nums` 中**所有**子数组范围的**和**。  
> 子数组是数组中一个连续**非空**的元素序列。  

> You are given an integer array `nums`. The **range** of a subarray of `nums` is the difference between the largest and smallest element in the subarray.  
> Return *the **sum of all** subarray ranges of `nums`*.  
> A subarray is a contiguous **non-empty** sequence of elements within an array.  

----------

#### I 暴力遍历

两次遍历即可  

```cpp
long long subArrayRanges(vector<int>& nums) 
{
    long long cnt = 0;
    for(int i = 0; i < nums.size(); ++i)
    {
        int curMax = -1000000000;
        int curMin = 1000000000;
        for(int j = 0; i + j < nums.size(); ++j)
        {
            curMax = max(curMax, nums[i + j]);
            curMin = min(curMin, nums[i + j]);
            cnt += (curMax - curMin);
        }
    }
    return cnt;
}
```

#### II 单调栈

我们分析每个位置的数字：
1. 当这个数字作为子数组的最小值时：  
   - 这个数字左侧的值都比他大
   - 这个数字右侧的值都比他大
2. 当这个数字作为子数组的最大值时：
   - 这个数字左侧的值都比他小
   - 这个数字右侧的值都比他小  

如果我们对任意位置满足上述条件的两组数字的下标做记录，并对下标进行运算，则可以立即得到任意位置的数字作为子数组最小值/最大值的范围  
根据此范围可以进一步计算出作为最小值/最大值时的总和  
此时将所有数字作为最大值的次数和所有数字作为最小值的次数相加，即可得到最终结果  
对于每个位置的左右两侧的最大值和最小值，则可以用单调栈来解决  

```cpp
long long subArrayRanges(vector<int>& nums) 
{
    int n = nums.size();
    stack<int> minStk;  //单调递增栈
    stack<int> maxStk;  //单调递减栈
    vector<int> minLeft(n);
    vector<int> minRight(n);
    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    for(int i = 0; i < n; ++i)
    {
        //记录每个位置左侧比它小的数字的下标位置，在下标该位置之后的数字都比它大，对它们来说最小数字都是当前位置
        while(!minStk.empty() && nums[minStk.top()] > nums[i])
            minStk.pop();
        minLeft[i] = minStk.empty() ? -1 : minStk.top();
        minStk.push(i);
        //记录每个位置左侧比它大的数字的下标位置，在下标该位置之后的数字都比它小，对它们来说最大数字都是当前位置
        while(!maxStk.empty() && nums[maxStk.top()] <= nums[i])
            maxStk.pop();
        maxLeft[i]  = maxStk.empty() ? -1 : maxStk.top();
        maxStk.push(i);
    }
    minStk = stack<int>();
    maxStk = stack<int>();
    for(int i = n - 1; i >= 0; --i)
    {
        //记录每个位置右侧比它小的数字的下标位置，在下标该位置之前的数字都比它大，对它们来说最小数字都是当前位置
        while(!minStk.empty() && nums[minStk.top()] >= nums[i])
            minStk.pop();
        minRight[i] = minStk.empty() ? n : minStk.top();
        minStk.push(i);
        //记录每个位置右侧比它大的数字的下标位置，在下标该位置之前的数字都比它小，对它们来说最小数字都是当前位置
        while(!maxStk.empty() && nums[maxStk.top()] < nums[i])
            maxStk.pop();
        maxRight[i] = maxStk.empty() ? n : maxStk.top();
        maxStk.push(i);
    }
    long long maxSum = 0;
    long long minSum = 0;
    for (int i = 0; i < n; i++) 
    {
        maxSum += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
        minSum += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
    }
    return maxSum - minSum;
}
```
