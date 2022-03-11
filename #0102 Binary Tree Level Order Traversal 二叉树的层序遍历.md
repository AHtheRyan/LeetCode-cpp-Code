### 二叉树的层序遍历
### Binary Tree Level Order Traversal

> 给你二叉树的根节点 `root`，返回其节点值的**层序遍历**。（即逐层地，从左到右访问所有节点）。  

> Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).  

----------

#### I 基于栈的BFS

见[从上到下打印二叉树 II](./%23剑指offer%2032%20-%20II.%20从上到下打印二叉树%20II.md)  

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> floor;
            for(int i = 0; i < size; ++i)
            {
                auto cur = q.front();
                q.pop();
                floor.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            ret.push_back(floor);
        }
        return ret;
    }
};
```
