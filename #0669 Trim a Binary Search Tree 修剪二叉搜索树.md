### 修剪二叉搜索树
### Trim a Binary Search Tree

> 给你二叉搜索树的根节点 `root`，同时给定最小边界 `low` 和最大边界 `high`。通过修剪二叉搜索树，使得所有节点的值在 `[low, high]` 中。修剪树**不应该**改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在**唯一的答案**。  
> 所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。  

> Given the `root` of a binary search tree and the lowest and highest boundaries as `low` and `high`, trim the tree so that all its elements lies in `[low, high]`. Trimming the tree should **not** change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a **unique answer**.  
> Return *the root of the trimmed binary search tree*. Note that the root may change depending on the given bounds.  

----------

#### I DFS迭代

由于树是二叉搜索树，  
首先，通过迭代可以找到符合条件的根：如果原来的根大于 `high`，则其右子树都不符合，所以 `root = root->left`，左子树小于 `low` 时同理  
确定好 `root` 后，考虑上下限，`root` 和子树的关系只有以下情况：  
- 左子树小于 `low`，存在右子树大的可能，所以将右子树变为当前父节点的左子树  
- 左子树大于 `low`，则左右子树肯定符合，直接迭代到下一个左子树进行判断  
- 右子树大于 `high` 与 小于 `high` 与左子树对称同理  

按照上述逻辑判断返回即可  

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
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        while(root && (root->val < low || root->val > high))
        {
            if(root->val < low)
                root = root->right;
            else
                root = root->left;
        }
        if(!root)
            return nullptr;
        TreeNode* t = root;
        while(t->left)
        {
            if(t->left->val < low)
                t->left = t->left->right;
            else
                t = t->left;
        }
        t = root;
        while(t->right)
        {
            if(t->right->val > high)
                t->right = t->right->left;
            else
                t = t->right;
        }
        return root;
    }
};
```
