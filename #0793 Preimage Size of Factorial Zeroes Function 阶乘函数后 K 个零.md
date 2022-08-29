### 阶乘函数后K个零
### Preimag Size of Factorial Zeroes Function

> `f(x)` 是 `x!` 末尾是 0 的数量。回想一下 `x! = 1 * 2 * 3 * ... * x`，且 `0! = 1`。  
> - 例如， `f(3) = 0`，因为 `3! = 6` 的末尾没有 0 ；而 `f(11) = 2`，因为 `11!= 39916800` 末端有 2 个 0。  
> 
> 给定 `k`，找出返回能满足 `f(x) = k` 的非负整数 `x` 的数量。  

> Let `f(x)` be the number of zeroes at the end of `x!`. Recall that `x! = 1 * 2 * 3 * ... * x` and by convention, `0! = 1`.  
> - For example, `f(3) = 0` because `3! = 6` has no zeroes at the end, while `f(11) = 2` because `11! = 39916800` has two zeroes at the end.  
> 
> Given an integer `k`, return the number of non-negative integers `x` have the property that `f(x) = k`.  

----------

#### I 二分法

查找位置可以利用二分来减少时间  
由于阶乘过程中 `2` 出现的频率远高于 `5`，因此只需要看 `5` 出现的次数，易知出现 `0` 的个数与任意 `k / 5` 直到 `k / 5 == 0` 时的所有商的和相等  

```cpp
class Solution 
{
public:
    int preimageSizeFZF(int k) 
    {
        return find(k + 1) - find(k);
    }

    int findnum(long x)
    {
        int ret = 0;
        while(x / 5)
        {
            ret += x / 5;
            x /= 5;
        }
        return ret;
    }

    int find(int k)
    {
        long left = 0;
        long right = 5000000000;
        while(left <= right)
        {
            long mid = left + (right - left) / 2;
            if(findnum(mid) < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};
```
