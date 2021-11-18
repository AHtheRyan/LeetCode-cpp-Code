### 二叉树的坡度
### Binary Tree Tilt

> 给定一个二叉树，计算 **整个树** 的坡度。  
> 一个树的 **节点的坡度** 定义即为，该节点左子树的节点之和和右子树节点之和的 **差的绝对值**。如果没有左子树的话，左子树的节点之和为 `0`；没有右子树的话也是一样。空结点的坡度是 `0`。  
> **整个树** 的坡度就是其所有节点的坡度之和。  

> Given the `root` of a binary tree, return *the sum of every tree node's **tilt***.  
> The **tilt** of a tree node is the **absolute difference** between the sum of all left subtree node **values** and all right subtree node **values**. If a node does not have a left child, then the sum of the left subtree node **values** is treated as `0`. The rule is similar if there the node does not have a right child.  

----------

#### I DFS

显然是一道DFS的题目  
这里只需要设置一个全局变量作为结果，再利用DFS求得每个节点所代表的 “子树及自身值之和” 并进行减法计算即可

```cpp
class Solution
{
public:
    int ret = 0;

    int findTilt(TreeNode* root)
    {
        curSum(root);
        return ret;
    }

    int curSum(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = curSum(root->left);
        int right = curSum(root->right);
        ret += abs(left - right);
        return left + right + root->val;
    }
};
```
