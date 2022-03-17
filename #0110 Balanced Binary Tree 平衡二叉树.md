### 平衡二叉树
### Balanced Binary Tree

> 给定一个二叉树，判断它是否是高度平衡的二叉树。  
> 本题中，一棵高度平衡二叉树定义为：  
> > 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。  

> Given a binary tree, determine if it is height-balanced.  
> For this problem, a height-balanced binary tree is defined as:  
> > a binary tree in which the left and right subtrees of every node differ in height by no more than 1.  

----------

#### I 自顶向下DFS

对每个点利用DFS计算高度，并求差值，如果任意点差值大于 `1`，则返回 `false`  

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

自顶向下的方法会对子树高度进行重复计算，这里可以从最底层开始传递信息  
遍历到最底层时，如果高度差已经大于 `1`，则直接返回 `-1`，在后续的过程中也都一直返回 `-1`，这样最后每棵子树都只判断一次即可  

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
