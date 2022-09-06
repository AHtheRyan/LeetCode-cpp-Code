### 二进制矩阵中的特殊位置
### Special Positions in a Binary Matrix

> 给你一个大小为 `rows x cols` 的矩阵 `mat`，其中 `mat[i][j]` 是 `0` 或 `1`，请返回**矩阵 `mat` 中特殊位置的数目**。  
> **特殊位置**定义：如果 `mat[i][j] == 1` 并且第 `i` 行和第 `j` 列中的所有其他元素均为 `0`（行和列的下标均**从 0 开始**），则位置 `(i, j)` 被称为特殊位置。  

> Given an `m x n` binary matrix `mat`, return *the number of special positions in `mat`*.  
> A position `(i, j)` is called **special** if `mat[i][j] == 1` and all other elements in row `i` and column `j` are `0` (rows and columns are **0-indexed**).  

----------

#### I 预记录

利用两个矩阵预先记录每行每列的 `1` 的数目  
再遍历 `mat`，每次遇到 `1` 判断其行列是否只有一个 `1` 即可  

```cpp
int numSpecial(vector<vector<int>>& mat) 
{
    int m = mat.size();
    int n = mat[0].size();
    vector<int> col(n);
    vector<int> row(m);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(mat[i][j] == 1)
            {
                ++col[j];
                ++row[i];
            }
    int cnt = 0;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(mat[i][j] == 1 && col[j] == 1 && row[i] == 1)
                ++cnt;
    return cnt;
}
```
