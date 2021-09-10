### 太平洋大西洋水流问题
### Pacific and Atlantic Waterflow

> 给定一个 `m x n` 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。  
> 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。  
> 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。  

> There is an `m x n` rectangular island that borders both the **Pacific Ocean** and **Atlantic Ocean**. The **Pacific Ocean** touches the island's left and top edges, and the **Atlantic Ocean** touches the island's right and bottom edges.  
> The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level** of the cell at `coordinate (r, c)`.  
> The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is **less than or equal to** the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.  
> Return a **2D list** of grid coordinates `result` where `result[i] = [ri, ci]` denotes that rain water can flow from cell `(ri, ci)` to **both** the Pacific and Atlantic oceans.  

----------

#### I 深度优先搜索

根据题意，需要判断从任意点能否到达两边的海，话句话说，就是任意出海口逆流而上能否到达某处陆地，  
因此，我们可以分别判断从大西洋和太平洋能否逆流而上，再取共同点即可，  
这里采用 **DFS** 算法，首先设置两个二维数组 `pacific` 和 `atlantic`，分别作为太平洋和大西洋逆流能否到达的标志，  
之后分别以东西和南北岸为起点，进行递归，最后遍历每个点确定是否同时满足两边的条件即可  
对于函数的解释如下：  
主函数部分用于初始化和计算返回结果，子函数部分用于进行对每个陆地点进行递归判断  

主函数的算法设置如下：  
设置两个二维数组 `pacific` 和 `atlantic`，以 `true` 记录逆流而上能到达该点，`false` 为不能到达该点，  
首先对东侧的太平洋和西侧的大西洋进行判断，利用DFS函数标记每个点
之后对南北侧的太平洋和大西洋进行判断，利用DFS函数标记每个点
最后遍历陆地每个点，如果大西洋和太平洋的标记均存在，则说明符合条件，将其加入返回数组  

DFS函数的算法设置如下：  
对于选定点 `heights[i][j]`，如果其标记过了，则返回（边界条件），  
否则，将其标记，并且对该点的东西南北四个点采用同样的过程

```cpp
//1.0版
//DFS分别对四个位置进行判断，使用了四个判断语句
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
{
    vector<vector<int>> ret;
    int x = heights.size();
    int y = heights[0].size();
    vector<vector<bool>> pacific(x, vector<bool> (y, false));
    vector<vector<bool>> atlantic(x, vector<bool> (y, false));
    for(int i = 0; i < x; ++i)
    {
        flowUp(heights, pacific, i, 0);
        flowUp(heights, atlantic, i, y - 1);
    }
    for(int i = 0; i < y; ++i)
    {
        flowUp(heights, pacific, 0, i);
        flowUp(heights, atlantic, x - 1, i);
    }
    for(int i = 0; i < x; ++i)
        for(int j = 0; j < y; ++j)
            if(atlantic[i][j] && pacific[i][j])
                ret.push_back({i, j});
    return ret;
}

void flowUp(vector<vector<int>>& heights, vector<vector<bool>>& mark, int i, int j)
{
    if(mark[i][j])
        return;
    mark[i][j] = true;
    if(j + 1 < heights[0].size() && heights[i][j + 1] >= heights[i][j])
        flowUp(heights, mark, i, j + 1);
    if(i + 1 < heights.size() && heights[i + 1][j] >= heights[i][j])
        flowUp(heights, mark, i + 1, j);
    if(i - 1 >= 0 && heights[i - 1][j] >= heights[i][j])
        flowUp(heights, mark, i - 1, j);
    if(j - 1 >= 0 && heights[i][j - 1] >= heights[i][j])
        flowUp(heights, mark, i, j - 1);
}

//2.0版
//采用循环的方式，简化了重复代码
vector<int> dir{-1, 0, 1, 0, -1};

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
{
    vector<vector<int>> ret;
    int x = heights.size();
    int y = heights[0].size();
    vector<vector<bool>> pacific(x, vector<bool> (y, false));
    vector<vector<bool>> atlantic(x, vector<bool> (y, false));
    for(int i = 0; i < x; ++i)
    {
        flowUp(heights, pacific, i, 0);
        flowUp(heights, atlantic, i, y - 1);
    }
    for(int i = 0; i < y; ++i)
    {
        flowUp(heights, pacific, 0, i);
        flowUp(heights, atlantic, x - 1, i);
    }
    for(int i = 0; i < x; ++i)
        for(int j = 0; j < y; ++j)
            if(atlantic[i][j] && pacific[i][j])
                ret.push_back({i, j});
    return ret;
}

void flowUp(vector<vector<int>>& heights, vector<vector<bool>>& mark, int i, int j)
{
    if(mark[i][j])
        return;
    mark[i][j] = true;
    int x, y;
    for(int k = 0; k < 4; ++k)
    {
        x = i + dir[k];
        y = j + dir[k + 1];
        if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && heights[x][y] >= heights[i][j])
            flowUp(heights, mark, x, y);
    }
}
```
