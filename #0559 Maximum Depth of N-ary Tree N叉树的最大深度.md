### N叉树的最大深度
### Maximum Depth of N-ary Tree

> 给定一个 N 叉树，找到其最大深度。  
> 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。  
> N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔。  

> Given a n-ary tree, find its maximum depth.  
> The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.  
> *Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value*.  

----------

#### I DFS

利用DFS，针对根节点的每个子节点依次进行深度计算即可  
本质上和二叉树并没有什么区别

```cpp
/*
// Definition for a Node.
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) 
    {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        return dfs(root, 0);
    }

    int dfs(Node* root, int depth)
    {
        if(!root)
            return depth;
        ++depth;
        int curdep = depth;
        for(auto child : root->children)
            curdep = max(curdep, dfs(child, depth));
        return curdep;
    }
};
```
