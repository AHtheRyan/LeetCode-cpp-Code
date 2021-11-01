### 岛屿的最大面积
### Max Area of Island

> 给你一个大小为 `m x n` 的二进制矩阵 `grid`。  
> 岛屿 是由一些相邻的 `1` (代表土地) 构成的组合，这里的「相邻」要求两个 `1` 必须在 **水平或者竖直的四个方向上** 相邻。你可以假设 `grid` 的四个边缘都被 `0`（代表水）包围着。  
> 岛屿的面积是岛上值为 `1` 的单元格的数目。  
> 计算并返回 `grid` 中最大的岛屿面积。如果没有岛屿，则返回面积为 `0`。  

> You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally** (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.  
> The **area** of an island is the number of cells with a value `1` in the island.  
> Return *the maximum **area** of an island in `grid`*. If there is no island, return `0`.  

----------

#### I 基于递归的DFS

显然，对于每个位置的陆地，可以分别检索其上下左右是否为陆地，如果是，则以其上下左右为中心继续检索，  
按照此思路写出深度优先搜索的算法即可，  
需要注意：  
1. 边界条件，即陆地位置不能超出范围（矩阵边界）  
2. 对于已经搜索过的陆地，有两种处理方式
   - 哈希表存储
   - 将调查过的陆地设置为非陆地，即 1 变成 0  

我们采用第二种方式处理

```cpp
int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int max = 0;
    int wid = grid.size();
    int len = grid[0].size();
    for (int i = 0; i < wid; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            if (grid[i][j] == 1)
            {
                int cur = accArea(grid, i, j, wid, len);
                max = max > cur ? max : cur;
            }
        }
    }
    return max;
}

int accArea(vector<vector<int>>& grid, int x, int y, int& wid, int& len)
{
    int cur = 1;
    grid[x][y] = 0;
    if (x - 1 >= 0 && grid[x - 1][y] == 1)
        cur += accArea(grid, x - 1, y, wid, len);
    if (y + 1 < len && grid[x][y + 1] == 1)
        cur += accArea(grid, x, y + 1, wid, len);
    if (y - 1 >= 0 && grid[x][y - 1] == 1)
        cur += accArea(grid, x, y - 1, wid, len);
    if (x + 1 < wid && grid[x + 1][y] == 1)
        cur += accArea(grid, x + 1, y, wid, len);
    return cur;
}
```

#### II 基于栈的DFS

与方法I思路相同，此处使用栈代替递归函数的职能，可实现相同的效果

```cpp
vector<int> direction{-1, 0, 1, 0, -1};

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(grid[i][j])
            {
                stack<pair<int, int>> stk;
                int cur = 1;
                grid[i][j] = 0;
                stk.push({i, j});
                while(!stk.empty())
                {
                    auto [r, c] = stk.top();
                    stk.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = r + direction[k];
                        int y = c + direction[k + 1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y])
                        {
                            grid[x][y] = 0;
                            ++cur;
                            stk.push({x, y});
                        }
                    }
                }
                maxArea = max(maxArea, cur);
            }
        }
    }
    return maxArea;
}
```
