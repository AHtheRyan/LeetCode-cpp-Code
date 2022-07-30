### 最大层内元素和
### Maximum Level Sum of a Binary Tree

> 给你一个二叉树的根节点 `root`。设根节点位于二叉树的第 `1` 层，而根节点的子节点位于第 `2` 层，依此类推。  
> 请返回层内元素之和**最大**的那几层（可能只有一层）的层号，并返回其中**最小**的那个。  

> Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.  
> Return the **smallest** level `x` such that the sum of all the values of nodes at level `x` is **maximal**.  

----------

#### I BFS

基础BFS的变体，每次录入一层节点后，记录该层的节点数再进行处理即可  

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
    int maxLevelSum(TreeNode* root) 
    {
        int maxv = INT_MIN;
        int floor = 0;
        int ret = 0;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            ++floor;
            int cur = 0;
            TreeNode* node = q.front();
            for(int i = 0; i < n; ++i)
            {
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
                cur += node->val;
                node = q.front();
            }
            if(cur > maxv)
            {
                maxv = cur;
                ret = floor;
            }
        }
        return ret;
    }
};
```
