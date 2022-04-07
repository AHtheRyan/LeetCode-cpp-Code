### 消失的区间
### Missing Ranges

> 给定一个排序的整数数组 ***nums***，其中元素的范围在**闭区间 `[lower, upper]`** 当中，返回不包含在数组中的缺失区间。  

> ou are given an inclusive range `[lower, upper]` and a **sorted unique** integer array `nums`, where all elements are in the inclusive range.  
> A number `x` is considered **missing** if `x` is in the range `[lower, upper]` and `x` is not in `nums`.  
> Return *the **smallest sorted** list of ranges that **cover every missing number exactly***. That is, no element of `nums` is in any of the ranges, and each missing number is in one of the ranges.  
> Each range `[a,b]` in the list should be output as:  
> - `"a->b"` if `a != b`  
> - `"a"` if `a == b`  

----------

#### I 端点插入

将 `lower` 和 `upper` 插入数组的前后两段，再进行顺序的区间比较即可

```cpp
class Solution 
{
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string> ret;
        nums.insert(nums.begin(), lower - 1);
        nums.emplace_back(upper + 1);
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            string cur;
            if(nums[i] + 1 != nums[i + 1])
                cur = trans(nums[i] + 1, nums[i + 1] - 1);
            else
                continue;
            ret.push_back(cur);
        }
        return ret;
    }

    string trans(int left, int right)
    {
        string cur = to_string(left);
        if(right == left)
            return cur;
        cur += "->";
        cur += to_string(right);
        return cur;
    }
};
```
