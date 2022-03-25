### 二叉树的最小深度
### Minimum Depth of Binary Tree

> 给定一个二叉树，找出其最小深度。  
> 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。  
> **说明**：叶子节点是指没有子节点的节点。  

> Given a binary tree, find its minimum depth.  
> The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.  
> **Note**: A leaf is a node with no children.  

----------

#### I 队列BFS

利用BFS，找到第一个没有左右子树的节点，该节点的深度即为二叉树的最小深度  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int minDepth(TreeNode* root) 
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
                if(!cur->left && !cur->right)
                    return depth;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return -1;
    }
};
```
