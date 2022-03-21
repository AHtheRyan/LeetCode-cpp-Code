### 爬楼梯
### Climbing Stairs

> 假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。  
> 每次你可以爬 `1` 或 `2` 个台阶。你有多少种不同的方法可以爬到楼顶呢？  

> You are climbing a staircase. It takes `n` steps to reach the top.  
> Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?  

----------

#### I 迭代

经典动态规划题

```cpp
int climbStairs(int n) 
{
    if(n <= 3)
        return n;
    int a = 3;
    int b = 2;
    int c;
    for(int i = 4; i <= n; ++i)
    {
        c = b;
        b = a;
        a = b + c;
    }
    return a;
}
```
