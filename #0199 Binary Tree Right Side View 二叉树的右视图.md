### 二叉树的右视图
### Binary Tree Right Side View

> 给定一个二叉树的**根节点** `root`，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。  

> Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.  

----------

#### I 双端队列 + BFS

基本的BFS思想，每次将当前层的最右侧节点的值记录即可

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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ret;
        if(!root)
            return ret;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty())
        {
            int n = q.size();
            ret.emplace_back(q.back()->val);
            for(int i = 0; i < n; ++i)
            {
                auto cur = q.front();
                q.pop_front();
                if(cur->left)   q.push_back(cur->left);
                if(cur->right)  q.push_back(cur->right);
            }
        }
        return ret;
    }
};
```
