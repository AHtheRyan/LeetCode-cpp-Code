### 二叉树中的搜索
### Search in a Binary Search Tree

> 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。  

> You are given the `root` of a binary search tree (BST) and an integer `val`.  
> Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.  

----------

#### I 迭代

二叉搜索树中，左子树的元素始终小于右子树的元素，依此性质直接进行迭代即可

```cpp
TreeNode* searchBST(TreeNode* root, int val) 
{
    while(root)
    {
        if(root->val == val)
            return root;
        root = root->val > val ? root->left : root->right;
    }
    return nullptr;
}
```

#### II 递归

与上同理，可以将迭代更改为递归的形式

```cpp
TreeNode* searchBST(TreeNode* root, int val) 
{
    if(!root)
        return nullptr;
    if(root->val > val)
        return searchBST(root->left, val);
    if(root->val < val)
        return searchBST(root->right, val);
    return root;
}
```
