### 两数相除
### Divide Two Integers

> 给定两个整数，被除数 `dividend` 和除数 `divisor`。将两数相除，要求不使用乘法、除法和 mod 运算符。  
> 返回被除数 `dividend` 除以除数 `divisor` 得到的商。  
> 整数除法的结果应当截去（`truncate`）其小数部分，例如：`truncate(8.345) = 8` 以及 `truncate(-2.7335) = -2`  

> Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.  
> Return the quotient after dividing `dividend` by `divisor`.  
> The integer division should truncate toward zero, which means losing its fractional part. For example, `truncate(8.345) = 8` and `truncate(-2.7335) = -2`.  
> **Note**: Assume we are dealing with an environment that could only store integers within the **32-bit** signed integer range: `[−231, 231 − 1]`. For this problem, assume that your function returns **`2^31 − 1` when the division result overflows**.

----------

#### I 二分法

对于被除数 `y` 和除数 `x`，我们只需要找到一个数字 `num`，使得 `x * num <= y` 且 `x * (num + 1) > y` 即可  
这里问题在于这里不能用乘法，所以需要用其它方式快速实现这样的过程  
采用自加的方式，可以使数据量每次变为原来的两倍，例如对于数字 `3`，第一次自加为 `3 + 3 = 6`，第二次为 `6 + 6 = 12`，可以看做第一次 `3 * 2^1 = 6`，第二次 `3 * 2^2 = 12`，  
这样，就可以通过自加的方式将乘法过程变为一个 `x` 和 `二进制 num` 的运算，  
例如对于被除数 `65`，可以看做 `3 * 22 == 3 * 10110b == 3 * (1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 1 * 2^1 + 0 * 2^1)`，其中2的幂即为上述自加过程的次数，  
在实际运算中，我们利用 `x` 的自加，确定自加结果中小于 `y` 的最大数，找到该数字后，再从低位到高位逐步确定每个自加结果的系数即可  
例如上面的例子，由于 `65 > 3 * 2^4 = 48` 且 `65 < 3 * 2^5 = 96`，所以结果必然处于 `11111` 和 `10000` 之间  
**注意**，考虑到溢出效应，对于 `INT_MIN` 需要专门处理


```cpp
int divide(int dividend, int divisor) 
{
    //判断除法运算结果为正数还是负数
    bool index;
    int num1 = (dividend >> 31) & 0x01;
    int num2 = (divisor >> 31) & 0x01;
    if(num1 ^ num2)
        index = false;
    else
        index = true;
    
    //考虑特殊情况
    if(divisor == 1)
        return dividend;
    if(divisor == -1)
        return dividend == INT_MIN ? INT_MAX : -dividend;
    if(dividend == 0)
        return 0;
    if(divisor == INT_MIN)
        return dividend == INT_MIN ? 1 : 0;
    if(dividend > 0)
        dividend = -dividend;
    if(divisor > 0)
        divisor = -divisor;
       
    //考虑一般情况
    int ret = 0;
    vector<int> candidate{divisor};
    while(dividend - candidate.back() <= candidate.back())
        candidate.push_back(candidate.back() + candidate.back());    
    for(int i = candidate.size() - 1; i >= 0; --i)
    {
        if(dividend - candidate[i] <= 0)
        {
            ret += (1 << i);
            dividend -= candidate[i];
        }
    }
    return index ? ret : -ret;
}
```
