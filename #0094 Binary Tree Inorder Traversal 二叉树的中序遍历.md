### 二叉树的中序遍历
### Binary Tree Inorder Traversal

> 给定一个二叉树的根节点 `root`，返回它的**中序**遍历。  

> Given the `root` of a binary tree, return *the inorder traversal of its nodes' values*.  

----------

#### I 递归

简单递归

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }

    void dfs(TreeNode* root, vector<int>& ret)
    {
        if(!root)
            return;
        if(root->left)  dfs(root->left, ret);
        ret.push_back(root->val);
        if(root->right) dfs(root->right, ret);
    }
};
```

#### II 迭代

简单迭代

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        stack<TreeNode*> stk;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            ret.emplace_back(root->val);
            root = root->right;
        }
        return ret;
    }
};
```

#### III Morris

利用Morris算法可以完成遍历过程  
其核心思想在于，将树变为链表，所有的右指针都指向节点的下一个需要遍历的节点  

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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        TreeNode* pre = new TreeNode;
        while(root)
        {
            if(!root->left)
            {
                ret.emplace_back(root->val);
                root = root->right;
            }
            else
            {
                pre = root->left;
                while(pre->right && pre->right != root)
                    pre = pre->right;
                if(!pre->right)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    ret.emplace_back(root->val);
                    pre->right = nullptr;
                    root = root->right;
                }
            }
        }
        return ret;
    }
};
```
