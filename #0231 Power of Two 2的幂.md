### 2的幂
### Power of Two

> 给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true`；否则，返回 `false`。  
> 如果存在一个整数 `x` 使得 `n == 2^x`，则认为 `n` 是 `2` 的幂次方。  

> Given an integer `n`, return *`true` if it is a power of two. Otherwise, return `false`*.  
> An integer `n` is a power of two, if there exists an integer `x` such that `n == 2^x`.  

----------

#### I bit运算性质

首先，小于等于 `0` 必然不满足条件  
根据bit位的特性，32位中某一位为 `1`，其他位为 `0` 则满足**2的幂**这一条件  
又因为对于任何一个**2的幂**，其减一的结果为后面的每位都变为 `1`，可以利用此性质判断是否为 `2` 的幂  
例如对于 `16 = 10000b`，其减一结果为 `15 = 01111b`，显然进行与运算后所有位都为 `0`  

```cpp
bool isPowerOfTwo(int n) 
{
    return n > 0 && (n & (n - 1)) == 0;
}
````
