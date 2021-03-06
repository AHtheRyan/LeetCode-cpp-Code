### 接雨水 II
### Trapping Rain Water II

> 给你一个 `m x n` 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。  

> Given an `m x n` integer matrix `heightMap` representing the height of each unit cell in a 2D elevation map, return *the volume of water it can trap after raining*.  

----------

#### I BFS

根据题意，整个接水的模块满足如下几个特点：  
1. 边界位置不能接水  
2. 每个单元的储水量不可能超过模块中最高的单元位置
3. 任意位置的储水量为周边四个位置最低的高度位置（木桶效应）  

根据上述特点规则进行整体的计算即可  
首先，求出整个模块中的最高单元  
其次，将边界位置的储水高度设置为边界的高度  
随后，利用BFS，将中间的位置的出水高度以上述规则求出  
最后，求出储水高度和模块的高度差并累加，即为总的接水量

```cpp
vector<int> direction{-1, 0, 1, 0, -1};

int trapRainWater(vector<vector<int>>& heightMap) 
{
    int m = heightMap.size();
    int n = heightMap[0].size();
    int maxHeight = 0;
    for(int i = 0; i < m; ++i)
        maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
    vector<vector<int>> water(m, vector<int>(n, maxHeight));
    queue<pair<int, int>> base;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                if(water[i][j] > heightMap[i][j])
                {
                    water[i][j] = heightMap[i][j];
                    base.push({i, j});
                }
    while(!base.empty())
    {
        auto [r, c] = base.front();
        base.pop();
        for(int k = 0; k < 4; ++k)
        {
            int x = r + direction[k];
            int y = c + direction[k + 1];
            if(x < 0 || y < 0 || x > m - 1 || y > n - 1)
                continue;
            if(heightMap[x][y] < water[x][y] && water[x][y] > water[r][c])
            {
                water[x][y] = max(heightMap[x][y], water[r][c]);
                base.push({x, y});
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            ret += water[i][j] - heightMap[i][j];
    return ret;
}
```

#### II 优先队列

同样先考虑最外面一圈，根据木桶效应，内部的积水肯定受最低的一块高度影响，  
可以先考虑最外圈的最低一块位置，设其为 `h`，其相邻的位置积水最高只能为 `h`，  
待该位置确定完高度后，将该位置继续看做最低的“墙”，继续缩小范围进行判断即可，  
由于每次都取当前的最矮的墙考虑，因此可以利用小顶堆进行相关计算过程  

```cpp
vector<int> direction{-1, 0, 1, 0, -1};

int trapRainWater(vector<vector<int>>& heightMap) 
{
    int m = heightMap.size();
    int n = heightMap[0].size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> wall;
    vector<vector<bool>> visited(m, vector<bool> (n, false));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                wall.push({heightMap[i][j], i * n + j});
                visited[i][j] = true;
            }
    int sum = 0;
    while(!wall.empty())
    {
        auto [r, c] = wall.top();
        wall.pop();
        for(int k = 0; k < 4; ++k)
        {
            int x = c / n + direction[k];
            int y = c % n + direction[k + 1];
            if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
                continue;
            if(heightMap[x][y] < r)
                sum += r - heightMap[x][y];
            visited[x][y] = true;
            wall.push({max(r, heightMap[x][y]), x * n + y});
        }
    }
    return sum;
}
```
