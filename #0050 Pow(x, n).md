### Pow(x, n)

>  实现 `pow(x, n)`，即计算 `x` 的 `n` 次幂函数（即，`x^n`）。  

> Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `x^n`).  

----------

#### I 矩阵快速幂

可以利用二进制进行运算优化  
例如，对于 `a` 的 `10` 次方，可以理解成 `a` 的 `1010` 次方，拆成 `a^8*1 + a^4*0 + a^2*1 + a^1*0`

```cpp
double myPow(double x, int n) 
{
  double ret = 1.0;
  long long N = (long long) n;
  while(N != 0)
  {
      if(N % 2)
          ret *= x;
      x *= x;
      N /= 2;
  }
  return n >= 0 ? ret : 1 / ret;
}
```
