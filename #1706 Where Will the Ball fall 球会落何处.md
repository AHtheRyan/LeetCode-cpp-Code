### 球会落何处
### Where Will the Ball Fall

> 用一个大小为 `m x n` 的二维网格 `grid` 表示一个箱子。你有 `n` 颗球。箱子的顶部和底部都是开着的。  
> 箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。  
> - 将球导向右侧的挡板跨过左上角和右下角，在网格中用 `1` 表示。  
> - 将球导向左侧的挡板跨过右上角和左下角，在网格中用 `-1` 表示。  
> 
> 在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。  
> 返回一个大小为 `n` 的数组 `answer`，其中 `answer[i]` 是球放在顶部的第 `i` 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 `-1`。  

> You have a 2-D `grid` of size `m x n` representing a box, and you have `n` balls. The box is open on the top and bottom sides.  
> Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.  
> - A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as `1`.  
> - A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as `-1`.  
> 
> We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.  
> Return *an array `answer` of size `n` where `answer[i]` is the column that the ball falls out of at the bottom after dropping the ball from the `ith` column at the top, or `-1` if the ball gets stuck in the box*.  

----------

#### I 模拟

分别对每个小球的下落情况进行模拟  
分类讨论落到下一行、被卡住的情况即可  

```cpp
vector<int> findBall(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> ret(n);
    for(int i = 0; i < n; ++i)
    {
        int col = i;
        int row = 0;
        for(; row < m; ++row)
        {
            if(col > 0 && grid[row][col] == -1 && grid[row][col - 1] == 1)
                break;
            if(col < n - 1 && grid[row][col] == 1 && grid[row][col + 1] == -1)
                break;
            col += grid[row][col];
            if(col == -1 || col == n)
                break;
        }
        ret[i] = row == m ? col : -1;
    }
    return ret;
}
```
