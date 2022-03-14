### 路径总和
### Path Sum

> 给你二叉树的根节点 `root` 和一个整数目标和 `targetSum`，找出所有**从根节点到叶子节点**路径总和等于给定目标和的路径。  
> **叶子节点**是指没有子节点的节点。  

> Given the `root` of a binary tree and an integer `targetSum`, return *all **root-to-leaf** paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node **values**, not node references*.  
> A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.  

----------

#### I 回溯

基于回溯进行查找即可  

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
    vector<vector<int>> ret;
    vector<int> cur;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        backtrack(root, targetSum);
        return ret;
    }

    void backtrack(TreeNode* root, int target)
    {
        if(!root)
            return;
        vector<int> origin = cur;
        cur.push_back(root->val);
        target -= root->val;
        if(!root->left && !root->right && target == 0)
            ret.push_back(cur);
        backtrack(root->left, target);
        backtrack(root->right, target);
        cur = origin;
    }
};
```
