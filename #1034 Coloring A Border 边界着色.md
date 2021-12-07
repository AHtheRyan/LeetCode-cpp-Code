### 边界着色
### Coloring A Border

> 给你一个大小为 `m x n` 的整数矩阵 `grid`，表示一个网格。另给你三个整数 `row`、`col` 和 `color`。网格中的每个值表示该位置处的网格块的颜色。  
> 当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一 **连通分量**。  
> **连通分量的边界** 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。  
> 请你使用指定颜色 `color` 为所有包含网格块 `grid[row][col]` 的 **连通分量的边界** 进行着色，并返回最终的网格 `grid`。  

> You are given an `m x n` integer matrix `grid`, and three integers `row`, `col`, and `color`. Each value in the grid represents the color of the grid square at that location.  
> Two squares belong to the same **connected component** if they have the same color and are next to each other in any of the 4 directions.  
> The **border of a connected component** is all the squares in the connected component that are either **4-directionally** adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).  
> You should color the **border** of the **connected component** that contains the square `grid[row][col]` with `color`.  
> Return *the final grid*.  

----------

#### I 基于队列的BFS

利用深度优先搜索简单判断即可

```cpp
class Solution 
{
public:
    vector<int> direction {-1, 0, 1, 0, -1};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int origin = grid[row][col];
        vector<vector<bool>> check(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            check[x][y] = true;
            for(int k = 0; k < 4; ++k)
            {
                int r = x + direction[k];
                int c = y + direction[k + 1];
                if(r < 0 || c < 0 || r > m - 1 || c > n - 1 || (!check[r][c] && grid[r][c] != origin))
                    grid[x][y] = color;
                else if(r >= 0 && c >= 0 && r < m && c < n && !check[r][c] && grid[r][c] == origin)
                    q.push({r, c});
            }
        }
        return grid;
    }
};
```
