### 岛屿的数量
### Number of Islands

> 给你一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格，请你计算网格中岛屿的数量。  
> 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。  

> Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.  
> An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.  

----------

#### I DFS

此题可以用深度优先和广度优先两种方法解，这里采用DFS  
在遇到岛屿时，首先将岛屿计数变量 `cnt` 加一  
由于岛屿都是连续陆地，所以可以利用DFS将每次遇到的岛屿“翻转”成海洋，这样在遍历的过程中就不会再碰到岛屿，从而实现完整的计数

```cpp
class Solution 
{
private:
    vector<int> dir{-1, 0, 1, 0, -1};

public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++cnt;
                    flip(grid, i, j);
                }
            }
        }
        return cnt;
    }

    void flip(vector<vector<char>>& grid, int row, int col)
    {
        stack<pair<int, int>> stk;
        stk.push({row, col});
        while(!stk.empty())
        {
            auto [x, y] = stk.top();
            stk.pop();
            grid[x][y] = '0';
            for(int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i];
                int ny = y + dir[i + 1];
                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1')
                    stk.push({nx, ny});
            }
        }
    }
};
```
