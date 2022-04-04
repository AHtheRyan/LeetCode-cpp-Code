### 丑数
### Ugly Number

> **丑数**就是只包含质因数 `2`、`3` 和 `5` 的正整数。  
> 给你一个整数 `n`，请你判断 `n` 是否为**丑数**。如果是，返回 `true`；否则，返回 `false`。  

> An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.  
> Given an integer `n`, return *`true` if `n` is an **ugly number***.  

----------

#### I 数学

直接把数字对 `2`、`3` 和 `5` 进行整除即可，如果最后不是 `1`，则该数字为丑数

```cpp
bool isUgly(int n) 
{
    if(n <= 0)
        return false;
    while(n % 2 == 0)
        n /= 2;
    while(n % 3 == 0)
        n /= 3;
    while(n % 5 == 0)
        n /= 5;
    return n == 1;
}
```
