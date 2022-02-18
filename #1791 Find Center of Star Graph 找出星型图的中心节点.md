### 找出星型图的中心节点
### Find Center of Star Graph

> 有一个无向的**星型**图，由 `n` 个编号从 `1` 到 `n` 的节点组成。星型图有一个**中心**节点，并且恰有 `n - 1` 条边将中心节点与其他每个节点连接起来。  
> 给你一个二维整数数组 `edges`，其中 `edges[i] = [ui, vi]` 表示在节点 `ui` 和 `vi` 之间存在一条边。请你找出并返回 `edges` 所表示星型图的中心节点。  

> There is an undirected **star** graph consisting of `n` nodes labeled from `1` to `n`. A star graph is a graph where there is one center node and exactly `n - 1` edges that connect the center node with every other node.  
> You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.  

----------

#### I 找出前两个连接中的共同点

显然，对于中心点，每个连接都会包含此点，因此，可以利用前两个连接，找出共同点，即为中心点  

```cpp
int findCenter(vector<vector<int>>& edges) 
{
    return edges[0][0] == edges[1][0] ? edges[0][0] : (edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1]);
}
```
