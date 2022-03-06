### 二维数组中的查找

> 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。  

----------

#### I 线性单调查找

本题与[搜索二维矩阵II](./%230240%20Search%20a%202D%20Matrix%20II%20搜索二维矩阵%20II.md)相同  

```cpp
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
    if(matrix.empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int x = 0;
    int y = n - 1;
    while(x >= 0 && x < m && y >= 0 && y < n)
    {
        if(matrix[x][y] > target)
            --y;
        else if(matrix[x][y] < target)
            ++x;
        else
            return true;
    }
    return false;
}
```
