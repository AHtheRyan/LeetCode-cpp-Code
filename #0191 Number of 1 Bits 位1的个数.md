### 位1的个数
### Number of 1 Bits

> 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为`汉明重量`）。  

> Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the `Hamming weight`).  

----------

#### I 迭代判断

按位进行判断即可

```cpp
int hammingWeight(uint32_t n) 
{
    int ret = 0;
    for(int i = 0; i < 32; ++i)
    {
        ret += (n & 1) == 1 ? 1 : 0;
        n >>= 1;
    }
    return ret;
}
```

#### II 位运算优化

利用 `n & (n - 1)` 可以消除 `n` 的最低位 `1` 的特征，减少迭代的次数  

```cpp
int hammingWeight(uint32_t n) 
{
    int ret = 0;
    while(n)
    {
        n &= (n - 1);
        ++ret;
    }
    return ret;
}
```
