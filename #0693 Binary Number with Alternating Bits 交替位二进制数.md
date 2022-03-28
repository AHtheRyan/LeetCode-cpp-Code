### 交替位二进制数
### Binary Number with Alternating Bits

> 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。  

> Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.  

----------

#### I 按位计算

每次计算最低位的值，确保发生变化即可  

```cpp
bool hasAlternatingBits(int n) 
{
    bool digit = (n & 1 == 1) ? false : true;
    while(n)
    {
        if(digit && (n & 1))
            return false;
        if(!digit && !(n & 1))
            return false;
        digit = !digit;
        n >>= 1;
    }
    return true;
}
```

#### II 数学

相邻位都不同的值隔位进行计算后值必为 `0...011111`不考虑先导 `0` 的话，则可认为每一位都为 `1`，  
此时可以将其加一，则结果为每一位都变为 `0`，除了溢出位的 `1`，可基于此进行简单的位运算判断  

```cpp
bool hasAlternatingBits(int n) 
{
    long a = n ^ (n >> 1);
    return (a & (a + 1)) == 0;
}
```
