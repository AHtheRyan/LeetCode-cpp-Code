### 最大二叉树II
### Maximum Binary Tree II

> **最大树**定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。  
> 给你最大树的根节点 `root` 和一个整数 `val`。  
> 树的创建规则见 [654 最大二叉树](./%230654%20Maximum%20Binary%20Tree%20最大二叉树.md)  
> 假设 `b` 是 `a` 的副本，并且在最后加入了一个新值 `val`，返回加入新值之后的树  

> A **maximum tree** is a tree where every node has a value greater than any other value in its subtree.  
> You are given the `root` of a maximum binary tree and an integer `val`.  
> The tree is built by the rules in [654 最大二叉树](./%230654%20Maximum%20Binary%20Tree%20最大二叉树.md)  
> Suppose `b` is a copy of `a` with a `val` appended to it, return the new tree constructed from `b`  

----------

#### I 迭代

根据树的构建规则，新的节点只可能在某个节点的右子节点或则根节点 `root`，（如果其出现在左子节点，说明该值小于该父节点，又由于该值接在数组最后，所以一定是先放在父节点的右侧）  
根据此规则进行迭代查找即可  

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) 
    {
        TreeNode* newNode = new TreeNode(val);
        if(val > root->val)
        {
            newNode->left = root;
            return newNode;
        }
        TreeNode* roll = root;
        while(roll->right && roll->right->val > val)
            roll = roll->right;
        TreeNode* tmp = roll->right;
        roll->right = newNode;
        newNode->left = tmp;
        return root;
    }
};
```
