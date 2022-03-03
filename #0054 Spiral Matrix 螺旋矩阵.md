### 螺旋矩阵
### Spiral Matrix

> 给你一个 `m` 行 `n` 列的矩阵 `matrix`，请按照**顺时针螺旋顺序**，返回矩阵中的所有元素。  

> Given an `m x n` `matrix`, return *all elements of the `matrix` in spiral order*.  

----------

#### I 模拟

每次前进都对矩阵进行判断，如果前进到了边沿就改变方向，  
改变顺序为 `右→下→左→上→右`  
这里可以利用一个数组记录每次的坐标变化  

```cpp
class Solution 
{
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> ret;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = 0;
        int pos = 0;
        for(int i = 0; i < m * n; ++i)
        {
            ret.push_back(matrix[row][col]);
            matrix[row][col] = 101;
            if(pos == 0 && (col == n - 1 || matrix[row][col + 1] == 101))
                ++pos;
            else if(pos == 1 && (row == m - 1 || matrix[row + 1][col] == 101))
                ++pos;
            else if(pos == 2 && (col == 0 || matrix[row][col - 1] == 101))
                ++pos;
            else if(pos == 3 && (row == 0 || matrix[row - 1][col] == 101))
                ++pos;
            pos = pos % 4;
            row += dir[pos][0];
            col += dir[pos][1];
        }
        return ret;
    }
};
```
