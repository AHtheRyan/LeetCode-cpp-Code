### 二叉树的最近公共祖先
### Lowest Ancestor of a Binary Tree

> 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。  
> 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”  

> Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.  
> According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”  

----------

#### I 递归

递归的核心在于，递归函数返回的内容可以说明找到了 `p` 或 `q` 节点，同时还能一直更新为子节点  
我们在 `root` 往子树搜索的过程中找到的节点往前返回，并在递归函数中监测是否存在非空指针返回，  
如果递归函数监测的返回为空指针，返回另一个方向的递归结果（根据题目条件，两个节点都存在）  
如果递归函数监测的返回都不为空指针，返回当前节点，且可以保证另一返回为空（因为两个节点都是此节点的子节点，另一方向的搜索必定无功而返）  

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

利用DFS找到两个节点并往上回溯其父节点，分别利用队列和哈希表记录，不断比较队列顶端的节点是否在哈希表中即可  

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
