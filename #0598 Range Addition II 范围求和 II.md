### 范围求和 II
### Range Addition II

> 给定一个初始元素全部为 **0**，大小为 m \* n 的矩阵 **M** 以及在 **M** 上的一系列更新操作。  
> 操作用二维数组表示，其中的每个操作用一个含有两个**正整数 a** 和 **b** 的数组表示，含义是将所有符合 **0 <= i < a** 以及 **0 <= j < b** 的元素 **M[i][j]** 的值都增加 **1**。  
> 在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。  

> You are given an `m x n` matrix `M` initialized with all `0`'s and an array of operations `ops`, where `ops[i] = [ai, bi]` means `M[x][y]` should be incremented by one for all `0 <= x < ai` and `0 <= y < bi`.  
> Count and return *the number of maximum integers in the matrix after performing all the operations*.  

----------

#### I 贪心

简而言之，由于总是包括右左上角的数字，所以对于每次给的边界做减法就可以  

```cpp
int maxCount(int m, int n, vector<vector<int>>& ops) 
{
    int row = m;
    int col = n;
    for(int i = 0; i < ops.size(); ++i)
    {
        row = row < ops[i][0] ? row : ops[i][0];
        col = col < ops[i][1] ? col : ops[i][1];
    }
    return row * col;
}
```
