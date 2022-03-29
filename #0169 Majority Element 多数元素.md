### 多数元素
### Majority Element

> 给定一个大小为 *n* 的数组，找到其中的多数元素。多数元素是指在数组中出现次数**大于**`⌊ n/2 ⌋`的元素。  
> 你可以假设数组是非空的，并且给定的数组总是存在多数元素。  

> Given an array `nums` of size `n`, return *the majority element*.  
> The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.  

----------

#### I Moore投票法

根据Moore投票法，多数元素所在的数字遇到其他元素则抵消，最后数组中剩下的元素只有多数元素，  
我们当然不能把元素删除（太费时间），但是我们可以遍历整个数组，  
先默认第一个数字为多数元素，如果下一个数字不等于他，则抵消，利用一个记号count计算当前选定的数字在遍历的过程中是否大于0，  
如果该数字减为0并且后面的数字不等于该选定的多数元素，那么就将新数字当做多数元素，  
遍历到最后即可知道没被抵消的元素是多少  

```cpp
int majorityElement(vector<int>& nums)
{
    int cur = nums[0];
    int size = nums.size();
    int count = 1;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] == cur)
            ++count;
        else if (nums[i] != cur && count)
            --count;
        else
        {
            cur = nums[i];
            ++count;
        }
    }
    return cur;
}
```

#### II 分治

利用分治法同样可以快速解题  
由于最小单元为1个数字，则必然众数为单元内的数字，之后，比较较大的单元，如果两个单元众数相同，则返回该数字，否则对两个数组进行比较，返回出现次数较多的数字  
最后的分治结果必然为众数  

```cpp
class Solution 
{
private:
    int cmpElements(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int cur1 = cmpElements(nums, left, mid);
        int cur2 = cmpElements(nums, mid + 1, right);
        if(cur1 == cur2)
            return cur1;
        int cnt1 = majority(nums, left, mid, cur1);
        int cnt2 = majority(nums, mid + 1, right, cur2);
        return cnt1 > cnt2 ? cur1 : cur2;
    }

    int majority(vector<int>& nums, int left, int right, int cur)
    {
        int ret = 0;
        for(int i = left; i <= right; ++i)
            if(cur == nums[i])
                ++ret;
        return ret;
    }

public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        return cmpElements(nums, 0, n - 1);
    }
};
```
