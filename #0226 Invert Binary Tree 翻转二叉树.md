### 翻转二叉树
### Invert Binary Tree

> 给你一棵二叉树的根节点 `root`，翻转这棵二叉树，并返回其根节点。  

> Given the `root` of a binary tree, invert the tree, and return *its root*.  

----------

#### I 递归

每次递归将树的左右两个子树对调即可  

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
            return root;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
```

#### II 迭代

利用层序遍历将每次遍历到的节点的左右子节点交换即可  

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)   return nullptr;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            auto l = cur->left;
            auto r = cur->right;
            cur->left = r;
            cur->right= l;
            if(l)   stk.push(l);
            if(r)   stk.push(r);
        }
        return root;
    }
};
```
