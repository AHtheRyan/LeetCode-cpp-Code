### 相同的树
### Same Tree

> 给你两棵二叉树的根节点 `p` 和 `q`，编写一个函数来检验这两棵树是否相同。  
> 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。  

> Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.  
> Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.  

----------

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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return (!p && !q) || p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

#### II 迭代

利用队列进行迭代对比即可  

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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(!p && !q)
            return true;
        if(!p && q || !q && p)
            return false;
        queue<TreeNode* > que1;
        queue<TreeNode* > que2;
        que1.push(p);
        que2.push(q);
        while(!que1.empty() && !que2.empty())
        {
            auto cur1 = que1.front();
            auto cur2 = que2.front();
            que1.pop();
            que2.pop();
            if(cur1->val != cur2->val)
                return false;
            if(!cur1->left && cur2->left || cur1->left && !cur2->left)   return false;
            else if(cur1->left)
            {
                que1.push(cur1->left);
                que2.push(cur2->left);
            }
            if(!cur1->right && cur2->right || cur1->right && !cur2->right)  return false;
            else if(cur1->right)
            {
                que1.push(cur1->right);
                que2.push(cur2->right);
            }
        }
        return true;
    }
};
```
