### 下一个更大元素 I
### Next Greater Element I

> 给你两个 没有重复元素 的数组 `nums1` 和 `nums2`，其中 `nums1` 是 `nums2` 的子集。  
> 请你找出 `nums1` 中每个元素在 `nums2` 中的下一个比其大的值。  
> `nums1` 中数字 `x` 的下一个更大元素是指 `x` 在 `nums2` 中对应位置的右边的第一个比 `x` 大的元素。如果不存在，对应位置输出 `-1`。  

> The **next greater element** of some element `x` in an array is the **first greater** element that is **to the right** of `x` in the same array.  
> You are given two **distinct 0-indexed** integer arrays `nums1` and `nums2`, where `nums1` is a subset of `nums2`.  
> For each `0 <= i < nums1.length`, find the index `j` such that `nums1[i] == nums2[j]` and determine the **next greater element** of `nums2[j]` in `nums2`. If there is no next greater element, then the answer for this query is `-1`.  
> Return *an array `ans` of length `nums1.length` such that `ans[i]` is the **next greater element** as described above*.  

----------

#### I 哈希表 + 单调栈

显然，如果可以记录 `nums2` 中每个数字后面大于其的第一个数字是多少，那么无论 `nums1` 作为其子集有多少元素，都可以根据记录的情况直接得出  
显然，这种记录可以利用哈希表解决，键值对分别为 **数字** 和 **大于其的第一个数字**  
再考虑如快速得到每一个数字对应的第一个大于其的数字  
显然，对于 `nums2` 中的最后一个位置 `k` 的数字来说，其后面没有数字，对应的值只能为 `-1`  
而对于其之前的数字：
1. 如果第 `k - 1` 位的数字，如果该数字大于 `k` 位的数字，则再往前的数字，只要小于 `k` 位的数字，都会被其屏蔽
2. 如果第 `k - 1` 位的数字，如果该数字小于 `k` 位的数字，则该位置前面的数字会考虑第 `k - 1` 位和第 `k` 位两个位置的数字

换句话说，对于数字 `a` 和 `b`（假设`a`在`b`的前面）  
若两者中间的某个数字 `c` 大于 `b`，那么就只需要考虑 `a` 和 `c` 的大小关系，`c` 屏蔽了 `b`  
若两者中间的某个数字 `d` 小于 `b`，那么还需要考虑 `a` 和 `d`，`a` 和 `b` 的分别关系  

所以，对于数组 `nums2`，我们考虑从后往前遍历，利用一个栈处理数字，通过对比和进出栈达到上述的单调查找的效果

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> ret;
    unordered_map<int, int> mp;
    stack<int> stk;
    for(int i = nums2.size() - 1; i >= 0; --i)
    {
        while(!stk.empty() && stk.top() < nums2[i])
            stk.pop();
        if(stk.empty())
            mp[nums2[i]]  = -1;
        else
            mp[nums2[i]] = stk.top();
        stk.push(nums2[i]);
    }
    for(auto num : nums1)
        ret.push_back(mp[num]);
    return ret;
}
```
