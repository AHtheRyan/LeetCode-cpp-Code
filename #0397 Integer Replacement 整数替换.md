### 整数替换
### Integer Replacement

> 给定一个正整数 `n`，你可以做如下操作：  
> 1. 如果 `n` 是偶数，则用 `n / 2` 替换 `n`。  
> 2. 如果 `n` 是奇数，则可以用 `n + 1` 或 `n - 1` 替换 `n`。  
> 
> `n` 变为 `1` 所需的最小替换次数是多少？  

> Given a positive integer `n`, you can apply one of the following operations:  
> 1. If `n` is even, replace `n` with `n / 2`.  
> 2. If `n` is odd, replace `n` with either `n + 1` or `n - 1`.  
> 
> Return *the minimum number of operations needed for `n` to become `1`*.  

----------

#### I BFS

显然，直接利用数字性质进行深度优先搜索即可

```cpp
int integerReplacement(int n) 
{
    if(n == 1)
        return 0;
    if(n % 2 == 0)
        return integerReplacement(n / 2) + 1;
    return min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) + 2;
}
```

#### II 贪心

可以对数字 `n` 进行分析：  
1. 如果 `n` 为偶数，则直接次数 +1，并将偶数除以 `2` 即可  
2. 如果 `n` 为奇数，则 `n % 4` 的结果有两种：
   - 结果为 `1`，则取 `n = (n - 1) / 2` 可使得次数最小，如果取 `n = (n + 1) / 2`，则结果为奇数，考虑该数字：  
     - 该数字 -1 之后为 `(n - 1) / 2`，所以次数会比直接取`(n - 1) / 2` 多  
     - 该数字 +1 之后再 /2 为 `(n + 3) / 4`，为 `(n - 1) / 2` /2 后 +1，则次数相同
   - 结果为 `3`，则取 `n = (n + 1) / 2` 可使次数最小，分析同上

因此，可以直接利用贪心求解     

```cpp
int integerReplacement(int n) 
{
    int ret = 0;
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            ++ret;
            n /= 2;
        }
        else 
        {
            ret += 2;
            if(n % 4 == 1)
                n /= 2;
            else if(n == 3)
                break;
            else if(n % 4 == 3)
                n = n / 2 + 1;
        }
    }
    return ret;
}
```
