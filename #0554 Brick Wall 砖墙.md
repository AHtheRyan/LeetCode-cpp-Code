### 砖墙
### Brick Wall

> 你的面前有一堵矩形的、由 `n` 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。  
> 你现在要画一条**自顶向下**的、穿过**最少**砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。你**不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的**。  
> 给你一个二维数组 `wall`，该数组包含这堵墙的相关信息。其中，`wall[i]` 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线**穿过的砖块数量最少**，并且返回**穿过的砖块数量**。  

> There is a rectangular brick wall in front of you with `n` rows of bricks. The `ith` row has some number of bricks each of the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.  
> Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.  
> Given the 2D array `wall` that contains the information about the wall, return *the minimum number of crossed bricks after drawing such a vertical line*.  

----------

#### I 哈希表

可以利用哈希表记录每排砖在第几个位置出现缝隙  
再计算出现缝隙次数最多的位置  
用总的排数减去出现缝隙最多的位置即可获得穿过砖的最小数量  

```cpp
int leastBricks(vector<vector<int>>& wall) 
{
    int n = wall.size();
    int width = 0;
    for(int i = 0; i < wall[0].size(); ++i)
        width += wall[0][i];
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 1; j < wall[i].size(); ++j)
        {
            wall[i][j] += wall[i][j - 1];
            ++mp[wall[i][j - 1]];
        }
    }
    int maxf = 0;
    for(auto& p : mp)
        maxf = max(maxf, p.second);
    return n - maxf;
}
```
