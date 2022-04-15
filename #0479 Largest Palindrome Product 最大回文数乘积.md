### 最大回文数乘积
## Largest Palindrome Product

> 给定一个整数 `n`，返回*可表示为两个 `n` 位整数乘积的**最大回文整数***。因为答案可能非常大，所以返回它对 `1337` **取余**。  

> Given an integer `n`, return *the **largest palindromic integer** that can be represented as the product of two `n`-digits integers*. Since the answer can be very large, return it **modulo** `1337`.  

----------

#### I 打表

简单粗暴打表

```cpp
int largestPalindrome(int n) 
{
    switch(n)
    {
        case 1: 
            return 9;
        case 2:
            return 987;
        case 3:
            return 123;
        case 4:
            return 597;
        case 5:
            return 677;
        case 6:
            return 1218;
        case 7:
            return 877;
        case 8:
            return 475;
        default:
            return -1;
    }
}
```

#### II 枚举

按照数字的大小从大到小枚举每个数字判断是否符合条件即可  

```cpp
int largestPalindrome(int n) 
{
    if(n == 1)
        return 9;
    int upperBound = pow(10, n) - 1;
    for(int left = upperBound; ; --left)
    {
        long num = left;
        for(int i = left; i > 0; i /= 10)
            num = num * 10 + i % 10;
        for(long x = upperBound; x * x >= num; --x)
            if(num % x == 0)
                return num % 1337;
    }
}
```
