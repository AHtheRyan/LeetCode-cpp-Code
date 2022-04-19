### 从中序遍历与后序遍历序列构造二叉树
### Construct Binary Tree from Inorder and Postorder Traversal

> 给定两个整数数组 `inorder` 和 `postorder`，其中 `inorder` 是二叉树的中序遍历，`postorder` 是同一棵树的后序遍历，请你构造并返回这颗*二叉树*。  

> Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return *the binary tree*.  

----------

#### I 递归

通过后序遍历和中序遍历的特征可以知道二叉树每个节点值的分布在数组中具有规律性  
可见[从前序与中序遍历序列构造二叉树](./%230105%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal%20从前序与中序遍历序列构造二叉树.md)的解答

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
    int postright;
    unordered_map<int, int> index;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
        for(int i = 0; i < n; ++i)
            index[inorder[i]] = i;
        this->postright = n - 1;
        return build(inorder, postorder, 0, n - 1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inleft, int inright)
    {
        if(inleft > inright)
            return nullptr;
        TreeNode* cur = new TreeNode(postorder[postright]);
        int curIndex = index[postorder[postright]];
        --postright;
        cur->right = build(inorder, postorder, curIndex + 1, inright);
        cur->left = build(inorder, postorder, inleft, curIndex - 1);
        return cur;
    }
};
```
