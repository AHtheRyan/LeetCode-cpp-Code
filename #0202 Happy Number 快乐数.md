### 快乐数
### Happy Number

> 编写一个算法来判断一个数 `n` 是不是快乐数。  
> **「快乐数」** 定义为：
> - 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。  
> - 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。  
> - 如果这个过程 结果为 1，那么这个数就是快乐数。  
> 
> 如果 `n` 是**快乐数**就返回 `true`；不是，则返回 `false`。  

> Write an algorithm to determine if a number `n` is happy.  
> A **happy number** is a number defined by the following process:  
> - Starting with any positive integer, replace the number by the sum of the squares of its digits.  
> - Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.  
> - Those numbers for which this process **ends in 1** are happy.  
> 
> Return *`true` if `n` is a happy number, and `false` if not*.  

----------

#### I 循环 + 哈希表

按位进行快乐数的判断循环，并用哈希表将数字记录，直到出现 `1` 或者出现重复数字为止  

```cpp
bool isHappy(int n) 
{
    unordered_set<int> st;
    while(n != 1)
    {
        st.insert(n);
        int x = 0;
        while(n)
        {
            int cur = n % 10;
            x += cur * cur;
            n /= 10;
        }
        if(st.count(x))
            return false;
        n = x;
    }
    return true;
}
```
