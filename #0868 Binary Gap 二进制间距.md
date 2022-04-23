### 二进制间距
### Binary Gap

> 给定一个正整数 `n`，找到并返回 `n` 的二进制表示中两个**相邻** 1 之间的**最长距离**。如果不存在两个相邻的 1，返回 `0`。  
> 如果只有 `0` 将两个 `1` 分隔开（可能不存在 `0`），则认为这两个 1 彼此**相邻**。两个 `1` 之间的距离是它们的二进制表示中位置的绝对差。例如，`"1001"` 中的两个 `1` 的距离为 3。  

> Given a positive integer `n`, find and return *the **longest distance** between any two **adjacent** `1`'s in the binary representation of `n`. If there are no two adjacent `1`'s, return `0`*.  
> Two `1`'s are **adjacent** if there are only `0`'s separating them (possibly no `0`'s). The **distance** between two `1`'s is the absolute difference between their bit positions. For example, the two `1`'s in `"1001"` have a distance of 3.  

----------

#### I 位运算

简单位运算

```cpp
int binaryGap(int n) 
{
    int distance = 0;
    int pos = -1;
    int cur = 0;
    while(n)
    {
        if(n & 1)
        {
            if(pos != -1)
                distance = max(distance, cur - pos);
            pos = cur;
        }
        ++cur;
        n >>= 1;
    }
    return distance;
}
```
