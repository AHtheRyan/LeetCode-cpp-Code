### 验证二叉搜索树
### Validate Binary Search Tree

> 给你一个二叉树的根节点 `root`，判断其是否是一个有效的二叉搜索树。  
> **有效**二叉搜索树定义如下：  
> - 节点的左子树只包含**小于**当前节点的数。  
> - 节点的右子树只包含**大于**当前节点的数。  
> - 所有左子树和右子树自身必须也是二叉搜索树。  

> Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.  
> A **valid BST** is defined as follows:  
> - The left subtree of a node contains only nodes with keys **less than** the node's key.  
> - The right subtree of a node contains only nodes with keys **greater than** the node's key.  
> - Both the left and right subtrees must also be binary search trees.  

----------

#### I 迭代

按中序遍历进行迭代，只要满足先遍历的数字比后遍历的数字大即可  

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
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode* > stk;
        long pre = static_cast<long>(INT_MIN) - 1;
        while(!stk.empty() || root != nullptr)
        {
            while(root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(root->val <= pre)
                return false;
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};
```

#### II 递归

与迭代原理相同，保证每个位置的节点值都能够满足在阈值范围之内即可  

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
    bool isValidBST(TreeNode* root) 
    {
        return retrieve(root, LONG_MIN, LONG_MAX);
    }

    int retrieve(TreeNode* root, long lower, long upper)
    {
        if(!root)
            return true;
        if(root->val >= upper || root->val <= lower)
            return false;
        return retrieve(root->left, lower, root->val) && retrieve(root->right, root->val, upper);
    }
};
```
