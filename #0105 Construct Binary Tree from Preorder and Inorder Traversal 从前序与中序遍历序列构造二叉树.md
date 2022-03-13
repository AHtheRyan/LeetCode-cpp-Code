### 从前序与中序遍历序列构造二叉树
### Construct Binary Tree from Preorder and Inorder Traversal  

> 给定两个整数数组 `preorder` 和 `inorder`，其中 `preorder` 是二叉树的先序遍历，`inorder` 是同一棵树的**中序遍历**，请构造二叉树并返回其根节点。  

> Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return *the binary tree*.  

----------

#### I 递归

见[重建二叉树](./%23剑指offer%2007.%20重建二叉树.md)

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
private:
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = preorder.size();
        for(int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        return recursion(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright)
    {
        if(inleft > inright)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preleft]);
        int rootIndex = index[preorder[preleft]];
        int lsize = rootIndex - inleft;
        root->left = recursion(preorder, inorder, preleft + 1, preleft + lsize, inleft, rootIndex - 1);
        int rsize = inright - rootIndex;
        root->right = recursion(preorder, inorder, preleft + lsize + 1, preright, rootIndex + 1, inright);
        return root;
    }
};
```

#### II 迭代



```cpp

```
