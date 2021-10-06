### 第三大的数
### Third Maximum Number

> 给你一个非空数组，返回此数组中 **第三大的数**。如果不存在，则返回数组中最大的数。

> Given an integer array `nums`, return *the **third distinct maximum** number in this array. If the third maximum does not exist, return the **maximum** number*.  

----------

#### I 排序

利用 `sort` 将数组由大到小排列，找出并返回第三大的数字即可

```cpp
int thirdMax(vector<int>& nums) 
{
    sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});
    int count = 1;
    int ret = nums[0];
    for(auto num : nums)
    {
        if(ret > num)
        {
            ret = num;
            ++count;
        }
        if(count == 3)
            return ret;
    }
    return nums[0];
}
```

#### II 集合

利用 `set` 自带的排序特性以及不相容性，始终将其中的元素数目控制在 3 一下，最后返回第一个元素即可  
如果元素数目小于 2，则返回最后一个元素

```cpp
int thirdMax(vector<int>& nums) 
{
    set<int> big3;
    for(auto num : nums)
    {
        big3.insert(num);
        if(big3.size() > 3)
            big3.erase(big3.begin()); 
    }
    return big3.size() == 3 ? *big3.begin() : *big3.rbegin();
}
```

#### III 记录

设置三个变量分别记录最大的数到第三大的数，遍历数组依次更新三个数字，最后返回第三大的数即可，  
为了避免不存在第三大的数，可以将每个数字都设置为可能出现的数字之外的一个小的数字，如果第三大的数字不为 `int类型`，则返回最大的数字

```cpp
int thirdMax(vector<int>& nums) 
{
    long a = LONG_MIN;
    long b = LONG_MIN;
    long c = LONG_MIN;
    for(auto num : nums)
    {
        if(num > a)
        {
            c = b;
            b = a;
            a = num;
        }
        else if(num < a && num > b)
        {
            c = b;
            b = num;
        }
        else if(num < b && num > c)
            c = num;
    }
    return c >= INT_MIN ? c : a;
}
```
