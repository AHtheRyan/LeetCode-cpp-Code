### 三维形体投影面积
### Protection Area of 3D Shapes

> 在 `n x n` 的网格 `grid` 中，我们放置了一些与 x，y，z 三轴对齐的 `1 x 1 x 1` 立方体。  
> 每个值 `v = grid[i][j]` 表示 `v` 个正方体叠放在单元格 `(i, j)` 上。  
> 现在，我们查看这些立方体在 `xy` 、`yz` 和 `zx` 平面上的投影。  
> **投影**就像影子，将**三维**形体映射到一个**二维**平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。  
> 返回*所有三个投影的总面积*。  

> You are given an `n x n` grid where we place some `1 x 1 x 1` cubes that are axis-aligned with the `x`, `y`, and `z` axes.  
> Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of the cell `(i, j)`.  
> We view the projection of these cubes onto the `xy`, `yz`, and `zx` planes.  
> A **projection** is like a shadow, that maps our **3-dimensional** figure to a **2-dimensional** plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.  
> Return *the total area of all three projections*.  

----------

#### I 模拟

简单模拟每个面的大小即可

```cpp
int projectionArea(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    int area1 = 0;
    int area2 = 0;
    int area3 = 0;
    for(int i = 0; i < m; ++i)
    {
        int h1 = 0;
        int h2 = 0;
        for(int j = 0; j < n; ++j)
        {
            if(grid[i][j] != 0) ++area1;
            h1 = max(h1, grid[i][j]);
            h2 = max(h2, grid[j][i]);
        }
        area2 += h1;
        area3 += h2;
    }
    return area1 + area2 + area3;
}
```
