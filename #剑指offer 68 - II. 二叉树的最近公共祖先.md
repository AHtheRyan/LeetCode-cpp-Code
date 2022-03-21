### 二叉树的最近公共祖先

> 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。  
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”  

----------

#### I 递归

见[二叉树的最近公共祖先](./%230236%20Lowest%20Ancestor%20of%20a%20Binary%20Tree%20二叉树的最近公共祖先.md)  

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root == p | root == q)
            return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        return l == nullptr ? r : (r == nullptr ? l : root);
    }
};
```

#### II DFS

见[二叉树的最近公共祖先](./%230236%20Lowest%20Ancestor%20of%20a%20Binary%20Tree%20二叉树的最近公共祖先.md)  

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        queue<TreeNode* > findP;
        queue<TreeNode* > findQ;
        dfs(root, p, findP);
        dfs(root, q, findQ);
        unordered_set<TreeNode*> st;
        while(!findP.empty())
        {
            st.insert(findP.front());
            findP.pop();
        }
        TreeNode* ret;
        while(!findQ.empty())
        {
            if(st.count(findQ.front()))
            {
                ret = findQ.front();
                break;
            }
            findQ.pop();
        }
        return ret;
    }

    void dfs(TreeNode* root, TreeNode* p, queue<TreeNode*>& findP)
    {
        if(root == p)
        {
            findP.push(root);
            return;
        }
        if(!root)
            return;
        dfs(root->left, p, findP);
        if(!findP.empty())
        {
            findP.push(root);
            return;
        }
        dfs(root->right, p, findP);
        if(!findP.empty())
        {
            findP.push(root);
            return;
        }
    }
};
```
