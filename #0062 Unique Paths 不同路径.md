### 不同路径
### Unique Paths

> 一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。  
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。  
> 问总共有多少条不同的路径？  

> There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.  
> Given the two integers `m` and `n`, return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.  
> The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.  

----------

#### I 动态规划

由于任何一个位置（除起点之外）都只有可能由其左边或者上面的位置移动到达，因此除了第一行和第一列每个位置都只有一种方法到达之外，  
其余每个位置的到达可能方法都是其上面和左边两个位置能够到达的方法之和，  
直接创建二维数组，利用上述思路初始化，并将最后一个位置的方法总数递推出来即可  

```cpp
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        dp[i][0] = 1;
    for (int i = 0; i < n; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < m; ++i)
        for (int j = 1; j < n; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}
```
