### 各位相加
### Add Digits

> 给定一个非负整数 `num`，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。

> Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.   

----------

#### I 数学

对数字进行找规律，可以发现其结果与数字本身除以 `9` 的余数有关，直接按规律返回即可  

```cpp
int addDigits(int num) 
{
    return num % 9 != 0 ? (num % 9) : (num == 0 ? 0 : 9);
}
```
