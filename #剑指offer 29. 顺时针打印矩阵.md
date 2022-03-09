### 顺时针打印矩阵

> 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。  

----------

#### I 模拟

见[螺旋矩阵](./%230054%20Spiral%20Matrix%20螺旋矩阵.md)  

```cpp
class Solution 
{
public:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty())
            return {};
        int pos = 0;
        int x = 0;
        int y = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ret;
        vector<vector<bool>> check(m, vector<bool> (n, false));
        for(int i = 0; i < m * n; ++i)
        {
            ret.push_back(matrix[x][y]);
            check[x][y] = true;
            if(pos == 0 && (y == n - 1 || check[x][y + 1]))
                ++pos;
            if(pos == 1 && (x == m - 1 || check[x + 1][y]))
                ++pos;
            if(pos == 2 && (y == 0 || check[x][y - 1]))
                ++pos;
            if(pos == 3 && (x == 0 || check[x - 1][y]))
                ++pos;
            pos %= 4;
            x += dir[pos][0];
            y += dir[pos][1];
        }
        return ret;
    }
};
```
