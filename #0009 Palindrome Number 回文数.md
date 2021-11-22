### 回文数
### Palindrome Number

> 给你一个整数 `x`，如果 `x` 是一个回文整数，返回 `true`；否则，返回 `false`。  
> 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，`121` 是回文，而 `123` 不是。  

> Given an integer `x`, return `true` if `x` is palindrome integer.  
> An integer is a **palindrome** when it reads the same backward as forward. For example, `121` is palindrome while `123` is not.  

----------

#### I 完全反转

简单反转即可

```cpp
bool isPalindrome(int x) 
{
    if(x < 0)
        return false;
    int tmp = x;
    int reverse_x = 0;
    while(tmp)
    {
        if(reverse_x > INT_MAX / 10)
            return false;
        reverse_x = reverse_x * 10 + tmp % 10;
        tmp /= 10;
    }
    if(reverse_x != x)
        return false;
    return true;
}
```

#### II 反转一半

如果直接反转一半的数字，再将其与剩下的一半比较，可以节约一半的时间，具体分析如下：  
- 如果数字的位数为偶数，则正好可将数字分为两半，如 `1221`，分为两个 `12` 即可  
- 如果数字的位数为奇数，则两半的数字一半会多出一位，此时可以将该位舍去，不影响比较，如 `12321`，分为 `12` 和 `123`，则直接将后面的 `3` 舍去再比较即可  
- 特殊情况：根据题意，负数直接舍去即可，对于末尾为 `0` 的非 `0` 数字，该数字也必不为回文数，可以直接返回 `false`

```cpp
bool isPalindrome(int x) 
{
    if(x < 0 || x % 10 == 0 && x != 0)
        return false;
    int half = 0;
    while(x > half)
    {
        half = half * 10 + x % 10;
        x /= 10;
    }
    return x == half || x == half / 10;
}
```
