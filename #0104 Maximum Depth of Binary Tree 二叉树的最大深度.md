### 二叉树的最大深度
### Maximum Depth of Binary Tree

> 给定一个二叉树，找出其最大深度。  
> 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。  
> **说明**: 叶子节点是指没有子节点的节点。  

> Given the `root` of a binary tree, return *its maximum depth*.  
> A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.  

----------

#### I 递归DFS

简单DFS

```cpp
class Solution 
{
private:
    int ret;

public:
    int maxDepth(TreeNode* root) 
    {
        int depth = 1;
        this->ret = 0;
        dfs(root, depth);
        return ret;
    }

    void dfs(TreeNode* root, int depth)
    {
        if(!root)
            return;
        ret = max(ret, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
```

#### II 队列BFS

简单BFS

```cpp
int maxDepth(TreeNode* root) 
{
    if(!root)
        return 0;
    int depth = 0;
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        ++depth;
        for(int i = 0; i < n; ++i)
        {
            auto cur = q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return depth;
}
```
