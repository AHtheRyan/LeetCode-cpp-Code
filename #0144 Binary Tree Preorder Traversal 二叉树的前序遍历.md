### 二叉树的前序遍历
### Binary Tree Preorder Traversal

> 给你二叉树的根节点 `root`，返回它节点值的**前序**遍历。  

> Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.  

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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        dfs(ret, root);
        return ret;
    }

    void dfs(vector<int>& ret, TreeNode* root)
    {
        if(!root)
            return;
        ret.emplace_back(root->val);
        dfs(ret, root->left);
        dfs(ret, root->right);
    }
};
```

#### II 基于栈的DFS

利用栈模拟递归过程，将每个节点的左右子节点按照**右→左**的顺序堆入栈中即可

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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int> ret;
        stack<TreeNode* > stk;
        stk.push(root);
        while(!stk.empty())
        {
            auto cur = stk.top();
            ret.emplace_back(cur->val);
            stk.pop();
            if(cur->right)
                stk.push(cur->right);
            if(cur->left)
                stk.push(cur->left);
        }
        return ret;
    }
};
```

#### III Morris遍历

将树转化为单链表处理即为Morris遍历的过程  
对于前序遍历，我们先看每个根节点是否有左子节点  
如果无，则将当前节点值记录，并将处理的节点变为当前节点的右子节点  
如果有，则先获得当前节点左子节点的最深的右子节点，记录当前节点的值，将右子节点的右指针指向当前节点，并取当前节点的左子节点进行处理

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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(!root)
            return {};
        vector<int> ret;
        TreeNode* pre = nullptr;
        while(root)
        {
            pre = root->left;
            if(pre)
            {
                while(pre->right && pre->right != root)
                    pre = pre->right;
                if(!pre->right)
                {
                    ret.emplace_back(root->val);
                    pre->right = root;
                    root = root->left;
                    continue;
                }
                else
                    pre->right = nullptr;
            }
            else
                ret.emplace_back(root->val);
            root = root->right;
        }
        return ret;
    }
};
```
