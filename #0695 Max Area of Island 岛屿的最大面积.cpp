/*
    显然，对于每个位置的陆地，可以分别检索其上下左右是否为陆地，如果是，则以其上下左右为中心继续检索，
    按照此思路写出深度优先搜索的算法即可，
    需要注意：
    1. 边界条件，即陆地位置不能超出范围（矩阵边界）
    2. 对于已经搜索过的陆地，有两种处理方式
        2.1 哈希表存储
        2.2 将调查过的陆地设置为非陆地，即 1 变成 0
       我们采用第二种方式处理
*/

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