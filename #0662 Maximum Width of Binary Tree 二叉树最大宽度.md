### 二叉树最大宽度
### Maximum Width of Binary Tree

> 给你一棵二叉树的根节点 `root`，返回树的**最大宽度**。  
> 树的**最大宽度**是所有层中最大的**宽度**。  
> 每一层的**宽度**被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 `null` 节点，这些 `null` 节点也计入长度。  

> Given the `root` of a binary tree, return *the **maximum width** of the given tree*.  
> The **maximum width** of a tree is the maximum **width** among all levels.  
> The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.  

----------

#### I BFS

利用BFS确定每个子节点是第几个位置，然后利用差值计算宽度即可

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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int ret = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while(!q.empty())
        {
            unsigned long long left = -1;
            unsigned long long right = -1;
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                auto p = q.front();
                q.pop();
                if(p.first->left)
                    q.push({p.first->left, 2 * p.second - 1});
                if(p.first->right)
                    q.push({p.first->right, 2 * p.second});
                if(left == -1)
                    left = p.second;
                right = p.second + 1;
            }
            ret = ret > right - left ? ret : right - left;
        }
        return ret;
    }
};
```
