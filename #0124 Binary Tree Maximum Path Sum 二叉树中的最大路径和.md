### 二叉树中的最大路径和
### Binary Tree Maximum Path Sum

> **路径**被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中**至多出现一次**。该路径**至少包含一个**节点，且不一定经过根节点。  
> **路径和**是路径中各节点值的总和。  
> 给你一个二叉树的根节点 `root`，返回其**最大路径和**。  

> A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.  
> The **path sum** of a path is the sum of the node's values in the path.  
> Given the `root` of a binary tree, return *the maximum **path sum** of any **non-empty** path*.  

----------

#### I 递归

分析每个节点时考虑如下：  
1. 如果考虑该节点加左右子树的最大值，则该值不能用于计算当前节点父节点（会形成岔路）  
2. 如果考虑该节点加左子树或者右子树的最大值，则两个值可能对父节点的路径产生贡献  

利用上述规律进行递归运算即可  

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
    int ret = INT_MIN;

public:
    int maxGain(TreeNode* node) 
    {
        if(!node)
            return 0;
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        int priceNewpath = node->val + leftGain + rightGain;
        ret = max(ret, priceNewpath);
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) 
    {
        maxGain(root);
        return ret;
    }
};
```
