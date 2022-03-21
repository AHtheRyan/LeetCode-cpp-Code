### 求1+2+...+n

> 求 `1+2+...+n`，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。  

----------

#### I 数学

利用高斯求和可知，结果为 `n * (n + 1) / 2`  
由于不能用除法，所以除以2的过程可以变为 `>>1`  
由于不能用乘法，所以可以设置一个规格为 `[n][n + 1]` 的数组，求其 `sizeof`，可获得同样的乘法结果  

```cpp
int sumNums(int n) 
{
    bool ret[n][n + 1];
    return sizeof(ret) >> 1;
}
```
