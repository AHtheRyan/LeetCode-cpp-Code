### 不同路径II
### Unique Path II

> 一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。  
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。  
> 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？  
> 网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。  

> A robot is located at the top-left corner of a `m x n` grid (marked 'Start' in the diagram below).  
> The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).  
> Now consider if some obstacles are added to the grids. How many unique paths would there be?  
> An obstacle and space is marked as `1` and `0` respectively in the grid.  

----------

#### I 动态规划

此题为[不同路径](./%230062%20Unique%20Paths%20不同路径.md)的延伸，区别在于障碍物的设计，  
显然，如果障碍物在起点或者终点，那么就无法实现**起点->终点**的过程，  
考虑其他情况，如果某个位置存在障碍物，那么其右侧和下侧就不能通过该位置到达，因此将该位置的方法直接设为 `0` 即可，  
按照上述思路初始化、递推整个数组即可  

```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i = 0; i < n && obstacleGrid[0][i] != 1; ++i)
        dp[0][i] = 1;
    for(int i = 0; i < m && obstacleGrid[i][0] != 1; ++i)
        dp[i][0] = 1;
    for(int i = 1; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            int up = obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j];
            int left = obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1];
            dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : up + left;
        }
    }
    return dp[m - 1][n - 1];
}
```
