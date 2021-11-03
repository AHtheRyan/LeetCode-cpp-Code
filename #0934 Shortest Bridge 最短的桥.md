### 最短的桥
## Shortest Bridge

> 在给定的二维二进制数组 `A` 中，存在两座岛。（岛是由四面相连的 `1` 形成的一个最大组。）  
> 现在，我们可以将 `0` 变为 `1`，以使两座岛连接起来，变成一座岛。  
> 返回必须翻转的 `0` 的最小数目。（可以保证答案至少是 `1`。）  

> In a given 2D binary array `grid`, there are two islands.  (An island is a 4-directionally connected group of `1`s not connected to any other 1s.)  
> Now, we may change `0`s to `1`s so as to connect the two islands together to form 1 island.  
> Return the smallest number of `0`s that must be flipped.  (It is guaranteed that the answer is at least 1.)  

----------

#### I DFS + BFS

首先利用遍历找到第一个岛，并针对第一个岛进行DFS，将该岛屿所有的陆地标为 `2`  
之后，以第一个岛屿为中心，利用BFS进行半径为 `1` 的逐步扩散，并将所有海洋标为 `2`  
最后，在某次遇到第二座岛时停止BFS，确认最短的桥的长度，即扩散的次数

```cpp
class Solution 
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> land;
        bool checked = false;
        for(int i = 0; i < row; ++i)
        {
            if(checked)
                break;
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                {
                    dfs(land, grid, row, col, i, j);
                    checked = true;
                    break;
                }
            }
        }
        int x, y;
        int bridge = 0;
        while(!land.empty())
        {
            ++bridge;
            int landArea = land.size();
            while(landArea--)
            {
                auto [r, c] = land.front();
                land.pop();
                for(int k = 0; k < 4; ++k)
                {
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if(x >= 0 && y >= 0 && x < row && y < col)
                    {
                        if(grid[x][y] == 2)
                            continue;
                        if(grid[x][y] == 1)
                            return bridge;
                        land.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
    
    void dfs(queue<pair<int, int>>& land, vector<vector<int>>& grid, int row, int col, int i, int j)
    {
        if(i < 0 || j < 0 || i == row || j == col || grid[i][j] == 2)
            return ;
        if(grid[i][j] == 0)
        {
            land.push({i, j});
            return ;
        }
        grid[i][j] = 2;
        dfs(land, grid, row, col, i - 1, j);
        dfs(land, grid, row, col, i, j - 1);
        dfs(land, grid, row, col, i + 1, j);
        dfs(land, grid, row, col, i, j + 1);
    }
};
```
