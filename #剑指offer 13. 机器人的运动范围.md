### 机器人的运动范围

> 地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]`。一个机器人从坐标 `[0, 0]` 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？  

----------

#### 广度优先搜索

朴实无华的广度优先搜索，  
由于从 `[0, 0]` 出发，可以只走**下**和**右**两个方向，用于剪枝，此外，设置标志位 `check` 同样用于剪枝，去除每次遍历过的位置  

```cpp
class Solution 
{
private:
    bool calc(int row, int col, int k)
    {
        int sum = 0;
        while(row || col)
        {
            sum += (row % 10 + col % 10);
            row /= 10;
            col /= 10;
        }
        return sum <= k;
    }

public:
    vector<int> dir{0, 1, 0};

    int movingCount(int m, int n, int k) 
    {
        vector<vector<bool>> check(m, vector<bool>(n));
        queue<pair<int, int>> q;
        q.push({0, 0});
        check[0][0] = true;
        int cnt = 0;
        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            ++cnt;
            for(int i = 0; i < 2; ++i)
            {
                int x = r + dir[i];
                int y = c + dir[i + 1];
                if(x < m && y < n && !check[x][y] && calc(x, y, k))
                {
                    check[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return cnt;
    }
};
```
