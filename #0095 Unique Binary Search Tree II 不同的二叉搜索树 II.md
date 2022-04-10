### 不同的二叉搜索树 II
### Unique Binary Search Tree II

> 给你一个整数 `n`，请你生成并返回所有由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的不同**二叉搜索树**。  

> Given an integer `n`, return *all the structurally unique **BST**'s (binary search trees), which has exactly `n` nodes of unique values from `1` to `n`*.  

----------

#### I 回溯

这道题的回溯比较巧妙，关键点在于针对不同层侧的节点都定义一个数组记录以该节点为根，剩下的节点为子节点构建的二叉搜索树  

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
    vector<TreeNode*> generateTrees(int n) 
    {
        vector<TreeNode* >ret = buildtree(1, n);
        return ret;
    }

    vector<TreeNode*> buildtree(int l, int r)
    {
        if(l > r)
            return {nullptr};
        vector<TreeNode*> ret;
        for(auto i = l; i <= r; ++i)
        {
            vector<TreeNode* > left = buildtree(l, i - 1);
            vector<TreeNode* > right = buildtree(i + 1, r);
            for(auto& lt : left)
            {
                for(auto& rt : right)
                {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = lt;
                    cur->right = rt;
                    ret.push_back(cur);
                }
            }
        }
        return ret;
    }
};
```
