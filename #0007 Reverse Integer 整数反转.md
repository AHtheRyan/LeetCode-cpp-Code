### 整数反转
### Reverse Integer

> 给你一个 32 位的有符号整数 `x`，返回将 `x` 中的数字部分反转后的结果。  
> 如果反转后整数超过 32 位的有符号整数的范围 `[−231,  231 − 1]`，就返回 `0`。  
> **假设环境不允许存储 64 位整数（有符号或无符号）**。  

> Given a signed 32-bit integer `x`, return *`x` with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-231, 231 - 1]`, then return `0`.  
> **Assume the environment does not allow you to store 64-bit integers (signed or unsigned)**.  

----------

#### I 按位反转

利用除法和取余操作，按位对数字反转即可  
可以对返回的数字进行判断，如果当前数字比带符号的最大整数大或者最小整数小，则直接返回 `0` 即可  

```cpp
int reverse(int x) 
{
    int ret = 0;
    while(x)
    {
        if(ret > INT_MAX / 10 || ret < INT_MIN / 10)
            return 0;
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}
```
