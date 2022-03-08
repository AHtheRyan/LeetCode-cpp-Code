### 二进制中1的个数

> 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为`汉明重量`）。  

----------

#### I 二进制循环

利用 `n & 1` 的形式依次判断最低位是否为 `1` 即可  

```cpp
int hammingWeight(uint32_t n) 
{
    int cnt = 0;
    for(int i = 0; i < 32; ++i)
    {
        if(n & 1)
            ++cnt;
        n >>= 1;
    }
    return cnt;
}
```

#### II 位运算优化

位运算 `n & (n - 1)` 可以用来消除最低位的 `1`，可以用此方法进行运算优化  

```cpp
int hammingWeight(uint32_t n) 
{
    int cnt = 0;
    while(n)
    {
        n &= n - 1;
        ++cnt;
    }
    return cnt;
}
```
