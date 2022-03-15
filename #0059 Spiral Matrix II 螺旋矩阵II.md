### 螺旋矩阵 II
### Spiral Matrix II

> 给你一个正整数 `n`，生成一个包含 `1` 到 `n^2` 所有元素，且元素按顺时针顺序螺旋排列的 `n x n` 正方形矩阵 `matrix`。  

> Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n^2` in spiral order.  

----------

#### I 模拟

1. 创建初始全部为 `0` 的二维矩阵，用来填补数字  
2. 按照**右->下->左->上**的顺序填补数字，填补时满足两个条件  
    2.1 下一个要填补的位置上的数字为 `0`  
    2.2 当前的行数和列数在二维矩阵的范围内  
3. 如果不满足上面的任意条件，则根据上述顺序转变方向  

```cpp
vector<vector<int>> generateMatrix(int n) 
{
    vector<vector<int>> ret(n, vector<int>(n));
    int num = 1;
    int l = 0;
    int r = n - 1;
    int t = 0;
    int b = n - 1;
    while(num <= n * n)
    {
        for(int i = l; i <= r; ++i)
            ret[t][i] = num++;
        ++t;
        for(int i = t; i <= b; ++i) 
            ret[i][r] = num++;
        --r;
        for(int i = r; i >= l; --i)
            ret[b][i] = num++;   
        --b;
        for(int i = b; i >= t; --i)
            ret[i][l] = num++;
        ++l;
    }
    return ret;
}
```
