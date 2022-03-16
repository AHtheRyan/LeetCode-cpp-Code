### 二叉搜索树的第k大节点

> 给定一棵二叉搜索树，请找出其中第 `k` 大的节点的值。  

----------

#### I 递归

二叉搜索树按照 `右子树->根->左子树` 的顺序遍历，可以实现从大到小遍历，可以利用递归完成此过程  
每次递归到一个节点，将 `k` 值减一，当 `k` 为 `0` 时，记录返回即可  

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
private:
    int ret;
    int k;

public:
    int kthLargest(TreeNode* root, int k) 
    {
        this->k = k;
        dfs(root);
        return ret;
    }

    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        if(root->right)
            dfs(root->right);
        if(--k == 0)
        {
            ret = root->val;
            return;
        }
        if(root->left)
            dfs(root->left);

    }
};
```
