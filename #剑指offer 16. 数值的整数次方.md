### 数值的整数次方

> 实现 `pow(x, n)`，即计算 x 的 n 次幂函数（即，x^n）。不得使用库函数，同时不需要考虑大数问题。  

----------

#### I 快速幂

具体分析见[Pow(x, n)](./%230050%20Pow(x%2C%20n).md)

```cpp
double myPow(double x, int n) 
{
    double ret = 1.0;
    bool pos = n >= 0 ? true : false;
    while(n)
    {
        if(n % 2)
            ret *= x;
        x *= x;
        n /= 2;
    }
    return pos ? ret : 1.0 / ret;
}
```
