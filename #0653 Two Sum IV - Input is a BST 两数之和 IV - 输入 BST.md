### 两数之和 IV - 输入 BST
### Two Sum IV - Input is a BST

> 给定一个二叉搜索树 `root` 和一个目标结果 `k`，如果BST中存在两个元素且它们的和等于给定的目标结果，则返回`true`。  

> Given the `root` of a Binary Search Tree and a target number `k`, return *`true` if there exist two elements in the BST such that their sum is equal to the given target*.  

----------

#### I BFS + 哈希表

在BFS遍历的过程中将数字记录，其他过程与[两数之和](./%230001%20Two%20Sum%20两数之和.md)相同  

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
    bool findTarget(TreeNode* root, int k) 
    {
        unordered_set<int> st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if(st.count(k - cur->val) == 0)
                st.insert(cur->val);
            else
                return true;
            if(cur->left)   q.push(cur->left);
            if(cur->right)  q.push(cur->right);
        }
        return false;
    }
};
```
