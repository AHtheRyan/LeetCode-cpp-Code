### 阶乘后的0
### Factorial Trailing Zeroes

> 给定一个整数 `n`，返回 `n!` 结果中尾随零的数量。  
> 提示 `n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1`  

> Given an integer `n`, return the number of trailing zeroes in `n!`.  
> Note that `n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1`.  

----------

#### I 数学

根据规律可以知道，一个数字含有几个因子 `5`，就会给阶乘结果增加几个 `0`  
因此，结果可以通过直接计算最大数字中 `5` 的数目得出  

```cpp
int trailingZeroes(int n) 
{
    int ret = 0;
    while(n / 5)
    {
        ret += n / 5;
        n /= 5;
    }
    return ret;
}
```
