### 树的子结构

> 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)  
> B是A的子结构， 即 A中有出现和B相同的结构和节点值。  

----------

#### I DFS查找

查找规则如下：  
- 如果初始有任意一棵树为空，则直接返回 `false`  
- 如果初始都不为空树，则对当前两个根节点进行判断  
- 1. 如果两个节点值相同，则进一步对左右子树进行判断
- 2. 如果 `B` 不存在，则返回 `true`，因为此时 `B` 可能为子结构
- 3. 如果 `A` 不存在或者两个节点值不同，则必然不为子结构，返回 `false`  
- 如果当前两个树的根节点不同，则进一步寻找 `A` 的左右子树作为根节点的新子树与 `B` 进行比较  

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
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if(!A || !B)
            return false;
        return compareTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool compareTree(TreeNode* root, TreeNode* B)
    {
        if(!B)
            return true;
        if(!root || root->val != B->val)
            return false;
        return compareTree(root->left, B->left) && compareTree(root->right, B->right);
    }
};
```
