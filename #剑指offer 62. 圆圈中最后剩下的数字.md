### 圆圈中最后剩下的数字

> 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。  
> 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。  

----------

#### I 队列

见[找出游戏的获胜者](./%231823%20Find%20the%20Winner%20of%20the%20Circular%20Game%20找出游戏的获胜者.md)  

```cpp
int lastRemaining(int n, int m)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int count = 0;
    while (q.size() > 1)
    {
        ++count;
        if (count == m)
        {
            count = 0;
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front();
}
```

#### II 数学

见[找出游戏的获胜者](./%231823%20Find%20the%20Winner%20of%20the%20Circular%20Game%20找出游戏的获胜者.md)  

```cpp
int lastRemaining(int n, int m) 
{
    int ret = 0;
    for(int i = 2; i <= n; ++i)
        ret = (ret + m) % i;
    return ret;
}
```
