### 3的幂
### Power of Three

> 给定一个整数，写一个函数来判断它是否是 `3` 的幂次方。如果是，返回 `true` ；否则，返回 `false`。  
> 整数 `n` 是 `3` 的幂次方需满足：存在整数 `x` 使得 `n == 3x`  

> Given an integer `n`, return *`true` if it is a power of three. Otherwise, return `false`*.  
> An integer `n` is a power of three, if there exists an integer `x` such that `n == 3x`.  

----------

#### I 基于定义的除法循环

基于定义循环除以3，看余数是否有3以外的数字即可  

```cpp
bool isPowerOfThree(int n) 
{
    while(n % 3 == 0 && n > 0)
        n /= 3;
    return n == 1;
}
```

#### II 自最大值向下的单次除法

由于在 `int` 范围内，最大值为 **1162261467**，所以在此范围内的3的幂都可以将其整除，直接计算即可  

```cpp
bool isPowerOfThree(int n) 
{
    return n > 0 && 1162261467 % n == 0;
}
```
