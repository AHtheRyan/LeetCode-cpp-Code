### 颠倒二进制位
### Reverse Bits

> 颠倒给定的 32 位无符号整数的二进制位。  

> Reverse bits of a given 32 bits unsigned integer.  

----------

#### I 位运算迭代

按位进行反转即可  

```cpp
uint32_t reverseBits(uint32_t n) 
{
    uint32_t ret = 0;
    for(int i = 0; i < 32; ++i)
    {
        ret <<= 1;
        ret += (n & 1);
        n >>= 1;
    }
    return ret;
}
```

#### II 位运算分治

可以利用逐位交换的方式将每一位进行交换，最后完成交换过程  

```cpp
class Solution 
{
private:
    const uint32_t M1 = 0x55555555;
    const uint32_t M2 = 0x33333333;
    const uint32_t M3 = 0x0F0F0F0F;
    const uint32_t M4 = 0x00FF00FF;

public:
    uint32_t reverseBits(uint32_t n) 
    {
        n = n >> 1 & M1 | (n & M1) << 1;
        n = n >> 2 & M2 | (n & M2) << 2;
        n = n >> 4 & M3 | (n & M3) << 4;
        n = n >> 8 & M4 | (n & M4) << 8;
        return n >> 16 | n << 16;
    }
};
```
