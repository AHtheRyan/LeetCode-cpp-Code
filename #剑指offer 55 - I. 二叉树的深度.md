### 二叉树的深度

> 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。  

----------

#### I DFS

见[二叉树的最大深度](./%230104%20Maximum%20Depth%20of%20Binary%20Tree%20二叉树的最大深度.md)  

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

#### II BFS

见[二叉树的最大深度](./%230104%20Maximum%20Depth%20of%20Binary%20Tree%20二叉树的最大深度.md)  

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
