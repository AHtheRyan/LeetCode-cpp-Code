### 省份数量
### Number of Provinces

> 有 `n` 个城市，其中一些彼此相连，另一些没有相连。如果城市 `a` 与城市 `b` 直接相连，且城市 `b` 与城市 `c` 直接相连，那么城市 `a` 与城市 `c` 间接相连。  
> **省份** 是一组直接或间接相连的城市，组内不含其他没有相连的城市。  
> 给你一个 `n x n` 的矩阵 `isConnected`，其中 `isConnected[i][j] = 1` 表示第 `i` 个城市和第 `j` 个城市直接相连，而 `isConnected[i][j] = 0` 表示二者不直接相连。  
> 返回矩阵中 **省份** 的数量。  

> There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.  
> A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.  
> You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the `ith` city and the `jth` city are directly connected, and `isConnected[i][j] = 0` otherwise.  
> Return *the total number of **provinces***.  

----------

### I 基于递归的BFS

由于相连的城市 `i` 和 `j` 相互必然包含着 `isConnected[i][j] == isConnected[j][i] == 1` 的关系，  
因此，我们只要通过某种方式，确保遍历关系网络 isConnected 时不会重复遍历即可，  
这里有两种思路：  
1. 设置标志位，遍历过的城市记为 true，未遍历记为 false  
2. 将遍历过的相互城市关系从 1 改变为 0  

这样就可以利用深度优先搜索对每个省份的关系网络进行判断  
两种思路的代码如下

```cpp
//设置标志位
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; ++i)
        {
            if (!visited[i])
            {
                mark(isConnected, visited, i);
                ++ret;
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j)
            if (isConnected[i][j] == 1 && !visited[j])
                mark(isConnected, visited, j);
    }
};
```

```cpp
//改变方阵本身
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        for (int i = 0; i < size; ++i)
        {
            if (isConnected[i][i] == 1)
            {
                ++ret;
                mark(isConnected, i);
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, int i)
    {
        for (int j = 0; j < isConnected.size(); ++j)
        {
            if (isConnected[i][j] == 1)
            {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                if (i != j)
                    mark(isConnected, j);
            }
        }
    }
};
```

#### II 基于栈的BFS

将递归的内容以栈的形式存储，同样可实现DFS  
这里直接改变了方阵本身  

```cpp
int findCircleNum(vector<vector<int>>& isConnected) 
{
    int cityNum = isConnected.size();
    int sum = 0;
    for(int row = 0; row < cityNum; ++row)
    {
        for(int col = 0; col < cityNum; ++col)
        {
            if(isConnected[row][col])
            {
                isConnected[row][col] = isConnected[col][row] = 0;
                stack<int> stk;
                stk.push(row);
                if(row != col)
                    stk.push(col);
                ++sum;
                while(!stk.empty())
                {
                    int r = stk.top();
                    stk.pop();
                    for(int i = 0; i < cityNum; ++i)
                    {
                        if(isConnected[r][i])
                        {
                            if(r != i)
                                stk.push(i);
                            isConnected[r][i] = isConnected[i][r] = 0;
                        }
                    }
                }
            }
        }
    }
    return sum;
}
```
