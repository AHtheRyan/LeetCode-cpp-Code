### 汇总区间
### Summary Ranges

> 给定一个**无重复元素**的**有序**整数数组 `nums`。  
> 返回***恰好覆盖数组中所有数字**的**最小有序**区间范围列表*。也就是说，`nums` 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 `nums` 的数字 `x`。  
> 列表中的每个区间范围 `[a,b]` 应该按如下格式输出：  
> - `"a->b"`，如果 `a != b`  
> - `"a"`，如果 `a == b`  

> You are given a **sorted unique** integer array `nums`.  
> A **range** `[a,b]` is the set of all integers from `a` to `b` (inclusive).  
> Return *the **smallest sorted** list of ranges that **cover all the numbers in the array exactly***. That is, each element of `nums` is covered by exactly one of the ranges, and there is no integer `x` such that `x` is in one of the ranges but not in `nums`.  
> Each range `[a,b]` in the list should be output as:  
> - `"a->b"` if `a != b`  
> - `"a"` if `a == b`  

----------

#### I 双指针

利用两个指针，左指针放在连续数字的起始位置，右指针放在最后的位置，每当右指针指到连续指针的最后一个，就将区间记录并记在返回数组中  

```cpp
vector<string> summaryRanges(vector<int>& nums) 
{
    vector<string> ret;
    int n = nums.size();
    int left = 0;
    int right = 0;
    while(right < n)
    {
        while(right < n && right + 1 < n && nums[right] + 1 == nums[right + 1])
            ++right;
        string cur = to_string(nums[left]);
        if(left != right)
        {
            cur += "->";
            cur += to_string(nums[right]);
        }
        ret.push_back(cur);
        ++right;
        left = right;
    }
    return ret;
}
```
