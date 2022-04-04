### 二叉树的所有路径
### Binary Tree Paths

> 给你一个二叉树的根节点 `root`，按**任意顺序**，返回所有从根节点到叶子节点的路径。  
> **叶子节点**是指没有子节点的节点。  

> Given the `root` of a binary tree, return *all root-to-leaf paths in **any order***.  
> A **leaf** is a node with no children.  

----------

#### I BFS

简单BFS

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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        queue<TreeNode*> q;
        queue<string> pq;
        q.push(root);
        pq.push("");
        vector<string> ret;
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            auto str = pq.front();
            pq.pop();
            str += to_string(cur->val);
            if(!cur->left &&!cur->right)
                ret.push_back(str);
            else
            {
                if(cur->left)
                {
                    q.push(cur->left);
                    string tmp = str + "->";
                    pq.push(tmp);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                    string tmp2 = str + "->";
                    pq.push(tmp2);
                }
            }
        }
        return ret;
    }
};
```

#### II 简答DFS

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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<int> rec;
        vector<string> ret;
        dfs(ret, root, rec);
        return ret;
    }

    void dfs(vector<string>& ret, TreeNode* root, vector<int>& rec)
    {
        if(!root->left && !root->right)
        {
            rec.push_back(root->val);
            string cur = to_string(rec[0]);
            for(int i = 1; i < rec.size(); ++i)
            {
                cur += "->";
                cur += to_string(rec[i]);
            }
            ret.push_back(cur);
            rec.pop_back();
            return;
        }
        rec.push_back(root->val);
        if(root->left)  dfs(ret, root->left, rec);
        if(root->right) dfs(ret, root->right, rec);
        rec.pop_back();
    }
};
```
