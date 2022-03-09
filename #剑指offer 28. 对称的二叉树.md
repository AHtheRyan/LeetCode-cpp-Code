### 对称的二叉树

> 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。  

----------

#### I 迭代

每次迭代比较当前对应位置的节点值，如果能比较且值相等，则进行后续操作，分别比较其左右两子树  
否则，直接返回 `false` 即可  

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
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        if(!l || !r || l->val != r->val)
            return false;
        return compare(l->left, r->right) && compare(l->right, r->left);
    }
};
```
