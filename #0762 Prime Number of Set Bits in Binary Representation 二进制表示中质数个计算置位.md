### 二进制表示中质数个计算置位
### Prime Number of Set Bits in Binary Representation

> 给你两个整数 `left` 和 `right`，在闭区间 `[left, right]` 范围内，统计并返回**计算置位位数为质数**的整数个数。  
> **计算置位位数**就是二进制表示中 `1` 的个数。  
> - 例如， `21` 的二进制表示 `10101` 有 `3` 个计算置位。  

> Given two integers `left` and `right`, return *the **count** of numbers in the **inclusive** range `[left, right]` having a **prime number of set bits** in their binary representation*.  
> Recall that the **number of set bits** an integer has is the number of `1`'s present when written in binary.  
> - For example, `21` written in binary is `10101`, which has `3` set bits.  

----------

#### I 打表 + 内置函数

利用C/C++自带的内置函数可以计算1的个数，在对质数进行打表，确定个数是否为质数即可  

```cpp
class Solution 
{
public:
    unordered_set<int> st{2, 3, 5, 7, 11, 13, 17, 19}; 

    int countPrimeSetBits(int left, int right) 
    {
        int ret = 0;
        for(int i = left; i <= right; ++i)
            if(st.count(__builtin_popcount(i)))
                ++ret;
        return ret;
    }
};
```

#### II 迭代计算

按要求求出每个数字的1的位数并判断是否为质数即可  

```cpp
class Solution 
{
public:
    int countPrimeSetBits(int left, int right) 
    {
        int ret = 0;
        for(int i = left; i <= right; ++i)
        {
            int x = digitCnt(i);
            if(isPrime(x))
                ++ret;
        }
        return ret;
    }

    int digitCnt(int x)
    {
        int ret = 0;
        while(x)
        {
            x &= (x - 1);
            ++ret;
        }
        return ret;
    }

    bool isPrime(int x)
    {
        if(x == 1)
            return false;
        int k = sqrt(x);
        for(int i = 2; i <= k; ++i)
            if(x % i == 0)
                return false;
        return true;
    }
};
```
