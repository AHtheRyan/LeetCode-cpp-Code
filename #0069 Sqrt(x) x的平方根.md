### x的平方根
### Sqrt(x)

> 给你一个非负整数 `x`，计算并返回 `x` 的**算术平方根**。  
> 由于返回类型是整数，结果只保留**整数部分**，小数部分将被**舍去**。  

> Given a non-negative integer `x`, compute and return *the square root of `x`*.  
> Since the return type is an integer, the decimal digits are **truncated**, and only **the integer part** of the result is returned.  

----------

#### I 二分法

常规二分思路

```cpp
int mySqrt(int x) 
{
    if(x <= 1)
        return x;
    int left = 0;
    int right = x;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(x / mid == mid)
            return mid;
        if(x / mid > mid && (mid + 1) > x / (mid + 1))
            return mid;
        else if(mid < x / mid)
            left = mid + 1;
        else if(mid > x / mid)
            right = mid - 1;
    }
    return -1;
}
```

#### II 牛顿法

随机选取一个点，计算该点的切线与x轴的交点，并计算交点与选取点横坐标的差值，不断将交点横坐标作为新选取的点，待差值小到一定程度后可以计算出平方根  

```cpp
int mySqrt(int x) 
{
    if(x == 0)
        return 0;
    double x0 = x;
    while(true)
    {
        double ret = x0 / 2 + x / (2 * x0);
        if(abs(ret - x0) < 1e-7)
            return int(ret);
        x0 = ret;
    }
    return -1;
}
```
