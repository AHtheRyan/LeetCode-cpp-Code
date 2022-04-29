### 建立四叉树
### Construct Quad Tree

> 给你一个 `n * n` 矩阵 `grid`，矩阵由若干 `0` 和 `1` 组成。请你用四叉树表示该矩阵 `grid`。  
> 你需要返回能表示矩阵的**四叉树**的根结点。  
> 注意，当 `isLeaf` 为 `False` 时，你可以把 `True` 或者 `False` 赋值给节点。  
> 四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：  
> - `val`：储存叶子结点所代表的区域的值。1 对应 **True**，0 对应 **False**；  
> - `isLeaf`: 当这个节点是一个叶子结点时为 **True**，如果它有 4 个子节点则为 **False**。  
```java
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```
> 我们可以按以下步骤为二维区域构建四叉树：  
> 1. 如果当前网格的值相同（即，全为 `0` 或者全为 `1`），将 `isLeaf` 设为 `True`，将 `val` 设为网格相应的值，并将四个子节点都设为 `Null` 然后停止。  
> 2. 如果当前网格的值不同，将 `isLeaf` 设为 `False`， 将 `val` 设为任意值，然后如下图所示，将当前网格划分为四个子网格。  
> 3. 使用适当的子网格递归每个子节点。  

> Given a `n * n` matrix `grid` of `0's` and `1's` only. We want to represent the `grid` with a Quad-Tree.  
> Return *the root of the Quad-Tree* representing the `grid`.  
> Notice that you can assign the value of a node to **True** or **False** when `isLeaf` is **False**, and both are **accepted** in the answer.  
> A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:  
> - `val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's.  
> - `isLeaf`: True if the node is leaf node on the tree or False if the node has the four children.
```java
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
```
> We can construct a Quad-Tree from a two-dimensional area using the following steps:  
> 1. If the current grid has the same value (i.e all `1's` or all `0's`) set `isLeaf` True and set `val` to the value of the grid and set the four children to Null and stop.  
> 2. If the current grid has different values, set `isLeaf` to False and set `val` to any value and divide the current grid into four sub-grids as shown in the photo.  
> 3. Recurse for each of the children with the proper sub-grid.  

----------

#### I 分治 + 递归 + 前缀和优化

核心思想在于找到叶子结点后回溯，而叶子结点满足其中的每个点都为 `1` 或者 `0`，因此可以使用前缀和进行优化，便于快速求和  

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution 
{
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> pre = grid;
        for(int i = 1; i < n; ++i)
        {
            pre[0][i] += pre[0][i - 1];
            pre[i][0] += pre[i - 1][0];
        }
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < n; ++j)
                pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        return decide(pre, 0, n - 1, 0, n - 1);
    }

    Node* decide(vector<vector<int>>& pre, int top, int bottom, int left, int right)
    {
        int height = bottom - top + 1;
        int sum = pre[bottom][right];
        if(left - 1 >= 0)
            sum -= pre[bottom][left - 1];
        if(top - 1 >= 0)
            sum -= pre[top - 1][right];
        if(left - 1 >= 0 && top - 1 >= 0)
            sum += pre[top - 1][left - 1];
        if(sum == 0 || sum == height * height)
            return new Node(sum == 0 ? 0 : 1, true);
        Node* cur = new Node;
        cur->topLeft = decide(pre, top, (top + bottom) / 2, left, (left + right) / 2);
        cur->topRight = decide(pre, top, (top + bottom) / 2, (left + right) / 2 + 1, right);
        cur->bottomLeft = decide(pre, (top + bottom) / 2 + 1, bottom, left, (left + right) / 2);
        cur->bottomRight = decide(pre, (top + bottom) / 2 + 1, bottom, (left + right) / 2 + 1, right);
        return cur;
    }
};
```
