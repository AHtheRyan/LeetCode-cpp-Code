### 第N位数字
### Nth Digit

> 给你一个整数 `n`，请你在无限的整数序列 `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]` 中找出并返回第 `n` 位上的数字。  

> Given an integer `n`, return the `nth` digit of the infinite integer sequence `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]`.  

----------

#### I 数学

见[数字序列中某一位的数字](./%23剑指offer%2044.%20数字序列中某一位的数字.md)  

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
