### 1~n整数中1出现的次数

> 输入一个整数 `n`，求1～n这n个整数的十进制表示中1出现的次数。  
> 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。  

----------

#### I 按位计算

见[数字1的个数](./%230233%20Number%20of%20Digit%20One%20数字1的个数.md)  

```cpp
int countDigitOne(int n) 
{
    int ret = 0;
    for(long k = 1; k <= n; k *= 10)
    {
        ret += n / (k * 10) * k;
        int candidate = n % (k * 10) - k + 1;
        candidate = candidate > 0 ? candidate : 0;
        candidate = candidate < k ? candidate : k;
        ret += candidate;
    }
    return ret;
}
```
