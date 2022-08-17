### 层数最深叶子节点的和
### Deepest Leaves Sum

> 给你一棵二叉树的根节点 `root`，请你返回**层数最深的叶子节点的和**。  

> Given the `root` of a binary tree, return *the sum of values of its deepest leaves*.  

----------

#### I BFS

简单BFS，将最后一层的结果累加即可  

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
    int deepestLeavesSum(TreeNode* root) 
    {
        int ret = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            ret = 0;
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto cur = q.front();
                q.pop();
                ret += cur->val;
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
        }
        return ret;
    }
};
```
