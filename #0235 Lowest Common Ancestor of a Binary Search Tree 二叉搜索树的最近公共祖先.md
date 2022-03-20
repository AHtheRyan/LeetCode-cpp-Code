### 二叉搜索树的最近公共祖先
### Lowest Common Ancestor of a Binary Search Tree

> 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。  
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”  

> Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.  
> According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”  

----------

#### I 迭代

二叉搜索树左子树的所有元素都比根节点小，右子树的所有元素都比根节点大  
因此，可以根据次性质不断寻找大于 `p` 且小于 `q` 的第一个节点并返回

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    int small = p->val > q->val ? q->val : p->val;
    int big = small == p->val ? q->val : p->val;
    while(true)
    {
        int num = root->val;
        if(num >= small && num <= big)
            return root;
        else if(num < small)
            root = root->right;
        else
            root = root->left;
    }
    return nullptr;
}
```
