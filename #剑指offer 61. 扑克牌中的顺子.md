### 扑克牌中的顺子

> 从**若干副扑克牌**中随机抽 `5` 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。  

----------

#### I 抽牌模拟

由于存在若干副扑克，首先在出现重复牌且该牌不为大小王牌的情况时直接返回 `false`  
此外，可以记录牌中最大和最小的牌，在排除了重复牌的情况下，只要两张牌差值小于 `5`，则可以成为顺子  

```cpp
bool isStraight(vector<int>& nums) 
{
    vector<int> cnt(14);
    int minnum = 14;
    int maxnum = 0;
    for(auto& num : nums)
    {
        ++cnt[num];
        if(num != 0)
        {
            minnum = min(minnum, num);
            maxnum = max(maxnum, num);
            if(cnt[num] > 1)
                return false;
        }
    }
    return maxnum - minnum < 5;
}
```
