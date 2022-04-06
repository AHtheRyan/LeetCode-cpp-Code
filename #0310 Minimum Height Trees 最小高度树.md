### 最小高度树
### Minimum Height Trees

> 树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。  
> 给你一棵包含 `n` 个节点的树，标记为 `0` 到 `n - 1`。给定数字 `n` 和一个有 `n - 1` 条无向边的 `edges` 列表（每一个边都是一对标签），其中 `edges[i] = [ai, bi]` 表示树中节点 `ai` 和 `bi` 之间存在一条无向边。  
> 可选择树中任何一个节点作为根。当选择节点 `x` 作为根节点时，设结果树的高度为 `h`。在所有可能的树中，具有最小高度的树（即，`min(h)`）被称为**最小高度树**。  
> 请你找到所有的**最小高度树**并按**任意顺序**返回它们的根节点标签列表。  
> 树的**高度**是指根节点和叶子节点之间最长向下路径上边的数量。  

> A tree is an undirected graph in which any two vertices are connected by *exactly* one path. In other words, any connected graph without simple cycles is a tree.  
> Given a tree of `n` nodes labelled from `0` to `n - 1`, and an array of `n - 1` `edges` where `edges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes `ai` and `bi` in the tree, you can choose any node of the tree as the root. When you select a node `x` as the root, the result tree has height `h`. Among all possible rooted trees, those with minimum height (i.e. `min(h)`)  are called **minimum height trees** (MHTs).  
> Return *a list of all **MHTs**' root labels*. You can return the answer in **any order**.  
> The **height** of a rooted tree is the number of edges on the longest downward path between the root and a leaf.  

----------

#### I BFS + 数学

可以证明，最小高度树的节点为距离最远的两个节点的中点的一个节点  
因此，可以用BFS找到距离最远的两个节点，并找出这两个节点的中间节点，返回即可  

```cpp
class Solution 
{
private:
    vector<vector<int>> mp;
    vector<int> parent;
    int n;

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        mp.resize(n);
        parent = vector<int> (n, -1);
        for(auto& edge : edges)
        {
            mp[edge[0]].emplace_back(edge[1]);
            mp[edge[1]].emplace_back(edge[0]);
        }
        vector<int> ret;
        int x = findLongest(0);
        int y = findLongest(x);
        parent[x] = -1;
        while (y != -1) 
        {
            ret.emplace_back(y);
            y = parent[y];
        }
        int m = ret.size();
        if (m % 2 == 0)
            return {ret[m / 2 - 1], ret[m / 2]};
        else
            return {ret[m / 2]};
    }

    int findLongest(int root)
    {
        int ret = -1;
        queue<int> q;
        q.push(root);
        vector<bool> checked(n, false);
        checked[root] = true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ret = cur;
            for(int j = 0; j < mp[cur].size(); ++j)
            {
                if(!checked[mp[cur][j]])
                {
                    checked[mp[cur][j]] = true;
                    q.push(mp[cur][j]);
                    parent[mp[cur][j]] = cur; 
                }
            }
        }
        return ret;
    }
};
```
