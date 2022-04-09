### 到达终点
### Reaching Points

> 给定四个整数 `sx`, `sy`，`tx` 和 `ty`，如果通过一系列的转换可以从起点 `(sx, sy)` 到达终点 `(tx, ty)`，则返回 `true`，否则返回 `false`。  
> 从点 `(x, y)` 可以转换到 `(x, x+y)`  或者 `(x+y, y)`。  

> Given four integers `sx`, `sy`, `tx`, and `ty`, return *`true` if it is possible to convert the point `(sx, sy)` to the point `(tx, ty)` through some operations, or `false` otherwise*.  
> The allowed operation on some point `(x, y)` is to convert it to either `(x, x + y)` or `(x + y, y)`.  

----------

#### I 辗转相除

采用正向搜索的方法，即令两个数字互相相加并探索可能性，会导致复杂度很高，因此可以进行逆向搜索，将两个终点数字减小  
这样可以比较两个数字，让两个数字相互取模，减少减法的操作过程  
完成减小过程后，可以比较两个更新完的终点数字和起点数字：  
- 如果 `tx == sx` 且 `ty == sy`，则直接返回 `true`  
- 如果 `tx == sy`，则可以比较 `ty - sy` 对 `sx` 取模的结果，如果能整除，说明能通过两个起点数字辗转相加得到，否则返回 `false`  
- 如果 `ty == tx`，同上  
- 如果两个终点数和起点数都不相等，则必然不能经过辗转相加得到，直接返回 `false`  

**注意**：`tx` 和 `ty` 取余的结果需要满足最后的更新终点数比起点数大，即 `ty > sy` `tx > sx`  

```cpp
bool reachingPoints(int sx, int sy, int tx, int ty) 
{
    while(tx > sx && ty > sy && tx != ty)
    {
        if(tx > ty)
            tx %= ty;
        else
            ty %= tx;
    }
    if(tx == sx && ty == sy)
        return true;
    else if(tx != sx && ty != sy)
        return false;
    else if(tx == sx)
        return ty > sy && (ty - sy) % sx == 0;
    else
        return tx > sx && (tx - sx) % sy == 0;
}
```
