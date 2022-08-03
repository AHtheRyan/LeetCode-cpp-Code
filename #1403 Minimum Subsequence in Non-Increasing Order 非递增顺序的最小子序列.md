### 非递增顺序的最小子序列
### Minimum Subsequence in Non-Increasing Order 

> 给你一个数组 `nums`，请你从中抽取一个子序列，满足该子序列的元素之和**严格**大于未包含在该子序列中的各元素之和。  
> 如果存在多个解决方案，只需返回**长度最小**的子序列。如果仍然有多个解决方案，则返回**元素之和最大**的子序列。  
> 与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。  
> 注意，题目数据保证满足所有约束条件的解决方案是 唯一 的。同时，返回的答案应当按 非递增顺序 排列。  

> Given the array `nums`, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence.   
> If there are multiple solutions, return the subsequence with **minimum size** and if there still exist multiple solutions, return the subsequence with the **maximum total sum** of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array.   
> Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in **non-increasing** order.  

----------

#### I 排序 + 倒序筛选

根据题意，满足条件的最大子序列显然是最大的几个元素组成的序列  
因此，可以排序后倒序计算后面元素的和，并与剩余元素进行比较，返回符合条件的子序列即可  

```cpp
vector<int> minSubsequence(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> ret;
    int calc = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        sum -= nums[i];
        calc += nums[i];
        ret.push_back(nums[i]);
        if(calc > sum)
            break;
    }
    return ret;
}
```
