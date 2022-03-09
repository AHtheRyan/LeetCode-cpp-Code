### 二叉树的镜像

> 请完成一个函数，输入一个二叉树，该函数输出它的镜像。  

----------

#### I 递归

见[翻转二叉树](%230226%20Invert%20Binary%20Tree%20翻转二叉树.md)  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* mirrorTree(TreeNode* root) 
    {
        if(!root)
            return root;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};
```
