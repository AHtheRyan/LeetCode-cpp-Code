### 数字序列中某一位的数字

> 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。  
> 请写一个函数，求任意第n位对应的数字。  

----------

#### I 数学

根据题目可得，对于位数为 `k` 的数字：  
1. `k == 1`，共有 `1~9` 共 `1 * 9 = 9` 个  
2. `k == 2`，共有 `10~99` 共 `2 * 90 = 180` 个  
3. `k == 3`，共有 `100~999` 共 `3 * 900 = 270` 个  

以此类推  
所以，我们可以根据此性质，找到第 `n` 个数字的位数 `k`，之后，可以利用减法运算获得的差，处理得到该数字为 `k` 位数的第 `mod` 个数字，获得最后的结果  

```cpp
int findNthDigit(int n) 
{
    long N = n;
    long digit = 1;
    long total = 9;
    while(N - digit * total > 0)
    {
        n -= digit * total;
        total *= 10;
        ++digit;
    }
    int initial = total / 9;
    int num = initial + (n - 1) / digit;
    int mod = (n - 1) % digit;
    string cur = to_string(num);
    return (cur[mod] - '0');
}
```
