### 矩阵置零
### Set Matrix Zeroes

> 给定一个 `m x n` 的矩阵，如果一个元素为**0**，则将其所在行和列的所有元素都设为**0**。请使用`原地`算法。  

> Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.  
> You must do it `in place`.  

----------

#### I 标记行列

先遍历矩阵，对需要置零的行和列进行标记  
再第二次遍历矩阵，对行和列进行置零操作即可  

```cpp
void setZeroes(vector<vector<int>>& matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    queue<pair<int, int>> q;
    vector<bool> checkCol(n, false);
    vector<bool> checkRow(m, false);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(matrix[i][j] == 0)
                q.push({i, j});
    while(!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        if(!checkRow[r])
        {
            for(int i = 0; i < n; ++i)
                matrix[r][i] = 0;
            checkRow[r] = true;
        }
        if(!checkCol[c])
        {
            for(int i = 0; i < m; ++i)
                matrix[i][c] = 0;
            checkCol[c] = true;
        }
    }
}
```
