### 平衡二叉树

> 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。  

----------

#### I 自顶向下DFS

见[平衡二叉树](./%230110%20Balanced%20Binary%20Tree%20平衡二叉树.md)  

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
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};
```

#### II 自底向上DFS

见[平衡二叉树](./%230110%20Balanced%20Binary%20Tree%20平衡二叉树.md)  

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
    bool isBalanced(TreeNode* root) 
    {
        return height(root) == -1 ? false : true;
    }

    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(left == -1 || right == -1 || abs(right - left) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
```
