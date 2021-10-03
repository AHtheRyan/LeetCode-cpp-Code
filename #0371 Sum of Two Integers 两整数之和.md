### 两整数之和
### Sum of Two Integers

> 给你两个整数 `a` 和 `b` ，**不使用**运算符 `+` 和 `-`，计算并返回两整数之和。  

> Given two integers `a` and `b`, return *the sum of the two integers without using the operators `+` and `-`*.  

----------

#### I 位运算

对于不使用 `+` 和 `-` 的运算，考虑从位运算中找到求和的方法，  
对于二元的异或运算，我们发现：  
- 1 ^ 1 = 0
- 1 ^ 0 = 1
- 0 ^ 1 = 1
- 0 ^ 0 = 0

可以作为不考虑进位的加法运算  
而对于二元的且运算，我们发现：
- 1 & 1 = 1
- 1 & 0 = 0
- 0 & 1 = 0
- 0 & 0 = 0

可以作为不考虑当前位的加法运算，
因此，可以将上述两种运算与 `<<` 相结合，实现与加法相同的效果

```cpp
int getSum(int a, int b) 
{
    while(b)
    {
        unsigned int c = unsigned(a & b) << 1;
        a = a ^ b;
        b = c;
    }
    return a;
}
```
