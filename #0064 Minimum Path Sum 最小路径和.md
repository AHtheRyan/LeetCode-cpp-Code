### 最小路径和
### Minimum Path Sum

> 给定一个包含非负整数的 `m x n` 网格 `grid`，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。  
> **说明**：每次只能向下或者向右移动一步。  

> Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.  
> **Note**: You can only move either down or right at any point in time.

----------

#### I 动态规划

此题为[不同路径](./%230062%20Unique%20Paths%20不同路径.md)的延伸，区别在于现在每走一步都需要获得格子上的数字（视为能量），  
采用动态规划，保证每一部所取的能量都是在该位置能取到的最小能量即可，  
换句话说，需要比较每一个格子左侧和上侧那个位置的能量比较小再将本位置的能量加上该较小能量，作为本位置的能量值  

```cpp
int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; ++i)
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    for (int row = 1; row < m; ++row)
        for (int col = 1; col < n; ++col)
            dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
    return dp[m - 1][n - 1];
}
```
