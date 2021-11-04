### 有效的完全平方数
### Valid Perfect Square

> 给定一个 **正整数** `num` ，编写一个函数，如果 `num` 是一个完全平方数，则返回 `true` ，否则返回 `false`。 

> Given a **positive** integer *num*, write a function which returns True if *num* is a perfect square else False.  

----------

#### I 二分查找

简单二分

```cpp
bool isPerfectSquare(int num) 
{
    if(num == 0)
        return true;
    int left = 1;
    int right = num;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(num / mid == mid && num % mid == 0)
            return true;
        else if(num / mid > mid || num / mid == mid && num % mid > 0)
            left = mid + 1;
        else if(num / mid < mid)
            right = mid - 1;
    }
    return false;
}
```

#### II 牛顿迭代法

渐进思想的牛顿迭代法

```cpp
bool isPerfectSquare(int num) 
{
    double x0 = num;
    while(true)
    {
        double x1 = (x0 * x0 + num) / (2 * x0);
        if(x0 - x1 < 1e-7)
            break;
        x0 = x1;
    }
    int x = x0;
    return x * x == num;
}
```
