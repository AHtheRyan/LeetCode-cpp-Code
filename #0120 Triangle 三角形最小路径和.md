### 三角形最小路径和
### Triangle

> 给定一个三角形 `triangle`，找出自顶向下的最小路径和。  
> 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是**下标**与**上一层结点下标**相同或者等于**上一层结点下标 + 1**的两个结点。也就是说，如果正位于当前行的下标 `i`，那么下一步可以移动到下一行的下标 `i` 或 `i + 1`。  

> Given a `triangle` array, return *the minimum path sum from top to bottom*.  
> For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.  

----------

#### I 动态规划

一道简单的动态规划题目，注意边界条件维护即可

```cpp
int minimumTotal(vector<vector<int>>& triangle)
{
    int size = triangle.size();
    int best;
    for (int i = size - 2; i >= 0; --i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            best = triangle[i + 1][j];
            if (j < i + 1)
                best = min(best, triangle[i + 1][j + 1]);
            triangle[i][j] += best;
        }
    }
    return triangle[0][0];
}
```
