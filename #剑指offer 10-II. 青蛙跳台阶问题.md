### 青蛙跳台阶问题

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 `n` 级的台阶总共有多少种跳法。  
> 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。  

----------

#### I 迭代

与[斐波那契数列](./%23剑指offer%2010-I.%20斐波那契数列.md)相同

```cpp
int numWays(int n) 
{
    if(n <= 1)
        return 1;
    int a = 1;
    int b = 1;
    int c;
    while(n > 1)
    {
        c = (a + b) % 1000000007;
        a = b;
        b = c;
        --n;
    }
    return c;
}
```
