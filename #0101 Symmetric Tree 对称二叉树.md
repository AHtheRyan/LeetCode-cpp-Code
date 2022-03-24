### 对称二叉树
### Symmetric Tree

> 给你一个二叉树的根节点 `root`， 检查它是否轴对称。

> Given the `root` of a binary tree, *check whether it is a mirror of itself*(i.e., symmetric around its center).  

-----------

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
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return cmp(root->left, root->right);
    }

    bool cmp(TreeNode* p, TreeNode* q)
    {
        return !p && !q || p && q && p->val == q->val && cmp(p->left, q->right) && cmp(p->right, q->left);
    }
};
```

#### II 迭代

利用队列进行广度优先遍历顺便进行比较

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
    bool isSymmetric(TreeNode* root) 
    {
        if(!root || !root->left && !root->right)
            return true;
        if(!root->left && root->right || root->left && !root->right)
            return false;
        queue<TreeNode* > que1;
        queue<TreeNode* > que2;
        que1.push(root->left);
        que2.push(root->right);
        while(!que1.empty() && !que2.empty())
        {
            auto cur1 = que1.front();
            auto cur2 = que2.front();
            que1.pop();
            que2.pop();
            if(cur1->val != cur2->val)
                return false;
            if(cur1->left && !cur2->right || !cur1->left && cur2->right)
                return false;
            if(cur1->left && cur2->right)
            {
                que1.push(cur1->left);
                que2.push(cur2->right);
            }
            if(cur1->right && !cur2->left || !cur1->right && cur2->left)
                return false;
            if(cur1->right && cur2->left)
            {
                que1.push(cur1->right);
                que2.push(cur2->left);
            }
        }
        return true;
    }
};
```
