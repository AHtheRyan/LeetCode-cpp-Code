### 二叉树的层序遍历 II
### Binary Tree Level Order Traversal II

> 给你二叉树的根节点 `root`，返回其节点值**自底向上的层序遍历**。  

> Given the `root` of a binary tree, return *the bottom-up level order traversal of its nodes' values*.  

----------

#### I BFS + 反转

将正向遍历的结果直接反转即可，正向遍历见 [二叉树的层序遍历](./%230102%20Binary%20Tree%20Level%20Order%20Traversal%20二叉树的层序遍历.md)  

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
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
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
