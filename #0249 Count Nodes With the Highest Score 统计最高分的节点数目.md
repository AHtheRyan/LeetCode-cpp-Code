### 统计最高分的节点数目
### Count Nodes With the Highest Score

> 给你一棵根节点为 `0` 的 二叉树 ，它总共有 `n` 个节点，节点编号为 `0` 到 `n - 1`。同时给你一个下标从**0**开始的整数数组 `parents` 表示这棵树，其中 `parents[i]` 是节点 `i` 的父节点。由于节点 `0` 是根，所以 `parents[0] == -1`。  
> 一个子树的**大小**为这个子树内节点的数目。每个节点都有一个与之关联的**分数**。求出某个节点分数的方法是，将这个节点和与它相连的边全部**删除**，剩余部分是若干个**非空**子树，这个节点的**分数**为所有这些子树**大小的乘积**。  
> 请你返回有**最高得分**节点的**数目**。  

> There is a **binary** tree rooted at `0` consisting of `n` nodes. The nodes are labeled from `0` to `n - 1`. You are given a **0-indexed** integer array `parents` representing the tree, where `parents[i]` is the parent of node `i`. Since node `0` is the root, `parents[0] == -1`.  
> Each node has a **score**. To find the score of a node, consider if the node and the edges connected to it were **removed**. The tree would become one or more **non-empty** subtrees. The **size** of a subtree is the number of the nodes in it. The **score** of the node is the **product of the sizes** of all those subtrees.  
> Return *the **number** of nodes that have the **highest score***.  

----------

#### I DFS

由于每个节点的权重与子树的值有关，因此，对于任意一个节点，我们可以记录其权重为 `子节点的数目 + 1（1 为其本身）`，  
这样，对于任意一个被去掉的数字，其得分可计算为：`左子节点的权重 × 右子节点的权重 ×（初始节点的权重 - 当前节点的权重）`  
为了得到上述计算公式，我们按一下步骤进行原数组处理：  
1. 记录每个节点的子节点，可以使用 `vector<vector<int>>` 或者 `unordered_map<int, vector<int>>`  
2. 设置 `vector<int>`，记录每个节点的权重，进行递归运算，递归过程如下：  
   - 终止条件：如果当前节点没有子节点，则直接将当前值的权重记为 `1` 并返回 `1`  
   - 否则返回 `当前值 + dfs(左子树) + dfs(右子树)`  
3. 通过上述方式获得节点权重后，按照前面描述的计算公式计算每个节点的分数，同时维护最高分和最高分的出现次数  
4. 返回最高分出现的次数  

```cpp
class Solution 
{
private:
   vector<vector<int>> dadToSon;   //记录每个节点的子节点所表示的数字是多少

public:
    int countHighestScoreNodes(vector<int>& parents) 
    {
        this->dadToSon = vector<vector<int>>(parents.size());
        for(int i = 1; i < parents.size(); ++i)
            dadToSon[parents[i]].push_back(i);
        vector<int> cnt(parents.size()); //记录每个节点的权重，即该节点的总的子节点的数量
        dfs(cnt, 0);
        long long maxret = 0;
        unordered_map<int, int> retCnt;
        for(int i = 0; i < cnt.size(); ++i)
        {
            long long product = 1;
            for(int j = 0; j < dadToSon[i].size(); ++j)
                product *= cnt[dadToSon[i][j]];
            product *= i == 0 ? 1 : (cnt[0] - cnt[i]);
            ++retCnt[product];
            maxret = max(maxret, product);
        }
        return retCnt[maxret];
    }

    int dfs(vector<int>& cnt, int cur)
    {
        if(dadToSon[cur].empty())
        {
            cnt[cur] = 1;
            return 1;
        }
        int sum = 1;
        for(int i = 0; i < dadToSon[cur].size(); ++i)
            if(!dadToSon.empty())
                sum += dfs(cnt, dadToSon[cur][i]);
        cnt[cur] = sum;
        return sum;
    }
};
```
