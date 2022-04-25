### 随机数索引
### Random Pick Index

> 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。  

> Given an integer array `nums` with possible **duplicates**, randomly output the index of a given `target` number. You can assume that the given target number must exist in the array.  
> Implement the `Solution` class:  
> - `Solution(int[] nums)` Initializes the object with the array `nums`.  
> - `int pick(int target)` Picks a random index `i` from `nums` where `nums[i] == target`. If there are multiple valid i's, then each index should have an equal probability of returning.  

----------

#### I 蓄水池抽样

采用蓄水池抽样法，每遇到一个目标数字 `target`，就将总计数 `cnt` 加一，再利用随机数取余，如果余为 `0`，就更新下标，否则下标不变  

```cpp
class Solution 
{
private:
    vector<int>& nums;

public:
    Solution(vector<int>& nums): nums(nums)
    {}
    
    int pick(int target) 
    {
        int ret = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                ++cnt;
                if(rand() % cnt == 0)
                    ret = i;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```
