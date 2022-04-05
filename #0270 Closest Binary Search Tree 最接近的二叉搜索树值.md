### 最接近的二叉搜索树值
### Closest Binary Search Tree

> 给定一个不为空的二叉搜索树和一个目标值 `target`，请在该二叉搜索树中找到最接近目标值 `target` 的数值。  

> Given the `root` of a binary search tree and a `target` value, return *the value in the BST that is closest to the `target`*.  

----------

#### I BFS

简单BFS  

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
    int closestValue(TreeNode* root, double target) 
    {
        double minDelta = DBL_MAX;
        int ret = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            double delta = abs(double(cur->val) - target);
            if(delta < minDelta)
            {
                minDelta = delta;
                ret = cur->val;
            }
            if(cur->left)  q.push(cur->left);
            if(cur->right)  q.push(cur->right);
        }
        return ret;
    }
};
```
