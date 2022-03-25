### 路径综合
### Path Sum

> 给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum`。判断该树中是否存在**根节点到叶子节点**的路径，这条路径上所有节点值相加等于目标和 `targetSum`。如果存在，返回 `true`；否则，返回 `false`。  
> **叶子节点**是指没有子节点的节点。  

> Given the `root` of a binary tree and an integer `targetSum`, return true if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.  
> A **leaf** is a node with no children.  

----------

#### I 递归

简单递归，当遍历到一个没有子节点的节点时，判断此时和是否为 `0` 即可  

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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)
            return false;
        targetSum -= root->val;
        if(!root->left && !root->right)
        {
            if(targetSum == 0)
                return true;
            return false;
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
```

#### II 队列BFS

与传统队列BFS的不同之处在于，需要两个队列，一个记录节点，顺便判断节点是否为最终的叶子节点，另一个记录从当前节点到根节点的和，用于作为判断条件  

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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(!root)   return false;
        queue<TreeNode* > node;
        queue<int> sum;
        node.push(root);
        sum.push(root->val);
        while(!node.empty())
        {
            int n = node.size();
            for(int i = 0; i < n; ++i)
            {
                auto curnode = node.front();
                node.pop();
                auto cursum = sum.front();
                sum.pop();
                if(!curnode->left && !curnode->right && cursum == targetSum)
                    return true;
                if(curnode->left)
                {
                    node.push(curnode->left);
                    sum.push(cursum + curnode->left->val);
                }
                if(curnode->right)
                {
                    node.push(curnode->right);
                    sum.push(cursum + curnode->right->val);
                }
            }
        }
        return false;
    }
};
```
