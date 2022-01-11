### 逃离大迷宫
### Escape a Large Maze

> 在一个 10^6 x 10^6 的网格中，每个网格上方格的坐标为 `(x, y)`。  
> 现在从源方格 `source = [sx, sy]` 开始出发，意图赶往目标方格 `target = [tx, ty]`。数组 `blocked` 是封锁的方格列表，其中每个 `blocked[i] = [xi, yi]` 表示坐标为 `(xi, yi)` 的方格是禁止通行的。  
> 每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格**不**在给出的封锁列表 `blocked` 上。同时，不允许走出网格。  
> 只有在可以通过一系列的移动从源方格 `source` 到达目标方格 `target` 时才返回 `true`。否则，返回 `false`。  

> There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are `(x, y)`.  
> We start at the `source = [sx, sy]` square and want to reach the `target = [tx, ty]` square. There is also an array of `blocked` squares, where each `blocked[i] = [xi, yi]` represents a blocked square with coordinates `(xi, yi)`.  
> Each move, we can walk one square north, east, south, or west if the square is **not** in the array of `blocked` squares. We are also not allowed to walk outside of the grid.  
> Return *`true` if and only if it is possible to reach the `target` square from the `source` square through a sequence of valid moves*.  

----------

#### I BFS

简单来说，利用BFS，确认从 `source` 到 `target` 是否完全被阻隔即可，  
但是问题在于，地图大小为 10^6 * 10^6，这样BFS耗时太长，  
注意到障碍物数量为 `200` 以内，较少，可以考虑对 `source` 和 `target` 分别BFS看是否完全被包围，  
这样就可以确定两点能否相连，  
可通过简单的几何数学证明包围的最大面积为（考虑两个边界）`n * (n - 1) / 2`，其中 `n` 为障碍物块的数量  
值得注意的点是，两者被包围在一个范围内也可以，因此进行BFS检索时应同时考虑能否直接相连

```cpp
class Solution 
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    unordered_set<long long> st;
    long long base = 13331;

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
    {
        for(auto block : blocked)
            st.insert(block[0] * base + block[1]);
        int size = blocked.size();
        int point = size * (size - 1) / 2;
        return encompass(source, target, point) & encompass(target, source, point);
    }

    bool encompass(vector<int>& source, vector<int>& target, int& point)
    {
        unordered_set<long long> check;
        queue<pair<int, int>> q;
        q.push(pair<int, int>{source[0], source[1]});
        while(!q.empty() && check.size() <= point)
        {
            auto [r, c] = q.front();
            check.insert(r * base + c);
            q.pop();
            for(int k = 0; k < 4; ++k)
            {
                int x = r + direction[k];
                int y = c + direction[k + 1];
                if(x == target[0] && y == target[1])
                    return true;
                if(x < 0 || y < 0 || x >= 1000000 || y >= 1000000 || st.count(x * base + y) || check.count(x * base + y))
                    continue;
                q.push({x, y});
                check.insert(x * base + y);
            }
        }
        return check.size() > point;
    }
};
```
